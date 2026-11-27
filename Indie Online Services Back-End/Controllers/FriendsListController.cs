using Indie_Online_Services_Back_End.Classes.Database;
using Indie_Online_Services_Back_End.Models;
using Microsoft.AspNetCore.Mvc;

namespace Indie_Online_Services_Back_End.Controllers;

[ApiController]
[Route("api/[controller]")]

public class FriendsListController : ControllerBase
{
    [HttpGet("get-friends-list/{userid:guid}")]
    public ActionResult<IEnumerable<FriendsListItem>> GetFriendsList(Guid userid)
    {
        if (userid == Guid.Empty) return BadRequest("user not logged in");

        FriendDatabaseCalls databaseCalls = new();
        List<FriendsListItem>? friends = databaseCalls.GetFriendsList_db(userid);

        if (friends is null) return StatusCode(StatusCodes.Status500InternalServerError, "Failed to retrieve friends list.");

        foreach (FriendsListItem item in friends)
        {
            Console.WriteLine(item.DisplayName);
        }

        return Ok(friends);
    }
}
