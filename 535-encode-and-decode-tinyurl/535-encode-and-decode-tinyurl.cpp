class Solution {
public:
    unordered_map<string, string> shorten;
    long long counter=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortened = "http://tinyurl.com/"+to_string(counter++);
        shorten[shortened]=longUrl;
        return shortened;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shorten[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));