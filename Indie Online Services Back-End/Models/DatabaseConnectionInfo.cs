using System.Text.Json.Serialization;

namespace Indie_Online_Services_Back_End.Models;

public readonly struct DatabaseConnectionInfo()
{
    [JsonPropertyName("host")]
    public string Host { get; init; } = string.Empty;

    [JsonPropertyName("username")]
    public string Username { get; init; } = string.Empty;

    [JsonPropertyName("password")]
    public string Password { get; init; } = string.Empty;

    [JsonPropertyName("port")]
    public int Port { get; init; } = 5432;

    [JsonPropertyName("database")]
    public string Database { get; init; } = "postgres";
}