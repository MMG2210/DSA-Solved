class Solution {
public:
    string url;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        this->url=longUrl;
        return this->url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return this->url;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));