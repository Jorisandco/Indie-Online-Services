using System;
using System.IO;
using System.Text.Json;
using Indie_Online_Services_Back_End.Models;
using Npgsql;

namespace Indie_Online_Services_Back_End.Classes.Database
{
    public class BaseDatabase
    {
        private DatabaseConnectionInfo? ConnectionInfo = null;
        public NpgsqlConnection? connection;
        protected string ConnectionString { get; private set; } = string.Empty;

        public BaseDatabase()
        {
            LoadConfig();
            connection = Connect();
        }

        private NpgsqlConnection Connect() {
            if (ConnectionString == string.Empty)
                throw new Exception("No connection string set");

            return new NpgsqlConnection(ConnectionString);
        }

        private void LoadConfig()
        {
            string configPath = Path.Combine(AppContext.BaseDirectory, "config", "config.json");

            Console.WriteLine(configPath);

            if (!File.Exists(configPath))
                
                throw new FileNotFoundException("Database config file not found.", configPath);

            string json = File.ReadAllText(configPath);
            if (string.IsNullOrWhiteSpace(json))
            {
                throw new InvalidOperationException("Config file is empty.");
            }

            ConnectionInfo = JsonSerializer.Deserialize<DatabaseConnectionInfo>(json);

            Console.WriteLine($"Host: '{ConnectionInfo.Value.Host}', Port: {ConnectionInfo.Value.Port}");

            NpgsqlConnectionStringBuilder builder = new()
            {
                Host = ConnectionInfo.Value.Host,
                Port = ConnectionInfo.Value.Port,
                Username = ConnectionInfo.Value.Username,
                Password = ConnectionInfo.Value.Password,
                Database = ConnectionInfo.Value.Database
            };

            ConnectionString = builder.ConnectionString;
        }
    }
}