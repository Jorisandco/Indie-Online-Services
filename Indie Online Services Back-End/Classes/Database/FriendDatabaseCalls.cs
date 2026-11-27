using Indie_Online_Services_Back_End.Models;
using Npgsql;
using NpgsqlTypes;

namespace Indie_Online_Services_Back_End.Classes.Database
{
    public class FriendDatabaseCalls : BaseDatabase
    {

        public List<FriendsListItem>? GetFriendsList_db(Guid userId) {
            try
            {
                if (userId == Guid.Empty) return null;

                connection.Open();

                string query = @"
                    SELECT
                    u.user_id,
                    u.displayname,
                    u.is_online
                    FROM friends f
                    INNER JOIN users u
                    ON u.user_id = CASE
                     WHEN f.friend_id_1 = @userId THEN f.friend_id_2
                        ELSE f.friend_id_1
                END
                WHERE (f.friend_id_1 = @userId OR f.friend_id_2 = @userId)
                 AND u.user_id <> @userId;";

                string userid_string = userId.ToString();
                using NpgsqlCommand comand = new NpgsqlCommand(query, connection);
                comand.Parameters.Add(new NpgsqlParameter("@userId", NpgsqlDbType.Varchar) { Value = userid_string });

                List<FriendsListItem> results = new List<FriendsListItem>();
                using NpgsqlDataReader reader = comand.ExecuteReader();



                while (reader.Read())
                {
                    Guid.TryParse(reader.GetString(0), out Guid playerId);

                    results.Add(new FriendsListItem
                    {
                        Playerid = playerId,
                        DisplayName = reader.GetString(1),
                        IsOnline = reader.GetBoolean(2),
                    });
                }

                return results;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error fetching friends list: {ex.Message}");
                return null;
            }
        }
    }
}