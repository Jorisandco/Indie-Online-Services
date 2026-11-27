namespace Indie_Online_Services_Back_End.Models;

public struct FriendsListItem(Guid Playerid, string DisplayName, bool IsOnline)
{
    public Guid Playerid { get; set; }  = Playerid; 
    public string DisplayName { get; set; } = DisplayName;
    public bool IsOnline { get; set; } = IsOnline; 
};