using Indie_Online_Services_Back_End.Models;
using Microsoft.AspNetCore.Mvc;

namespace Indie_Online_Services_Back_End.Controllers;

[ApiController]
[Route("api/[controller]")]

public class FriendsListController : ControllerBase
{
    [HttpGet("test")]
    public ActionResult<IEnumerable<FriendsListItem>> GetTestFriendList()
    {
        List<FriendsListItem> sampleFriends = new List<FriendsListItem>
        {
            new(Guid.Parse("11111111-1111-1111-1111-111111111111"), "JorisandCo", true),
            new(Guid.Parse("22222222-2222-2222-2222-222222222222"), "Morgumeow", false),
            new(Guid.Parse("33333333-3333-3333-3333-333333333333"), "RealUnrealGamer620", true)
        };

        return Ok(sampleFriends);
    }
}
