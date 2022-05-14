class Solution {
 public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

    //Sort tiles by start index , this also gurantee that tiles will also sorted by end index due to non overlapping condition
    sort(tiles.begin(), tiles.end());
    int n = tiles.size();

    // store prefix sum of each tiles , basically pre[i] denote (total white tiles in tiles at index i) + total white tiles before ith tiles.
    // et[i] will store end location of ith tiles  
    int prefix[n + 1], et[n];

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
      et[i] = tiles[i][1];
    }

    int ans = 0;

    //take each tiles[i][0] as start location of carpet and End will be start + carpetLen - 1
    // now search total tiles that can be cover in start and end of target
    // Basically you need to search end of carpet in et array (store end location of tiles)
    // calculate total white tiles in carpet between start index i and end index receive by search, using prefix sum array
    for (int i = 0; i < n; i++) {
      int start = tiles[i][0];
      int end = start + carpetLen - 1;

      int indx = upper_bound(et, et + n, end) - et;

      // tsum will store number of white tiles covered by carpet between i and indx - 1 ,reason for indx - 1 because we are using upper bound that will always return indx whose value is greater than end.
      int tsum = prefix[indx] - prefix[i];

      // now add tiles between end and indx covered by carpet
      if (indx < n and end >= tiles[indx][0]) tsum += end - tiles[indx][0] + 1;

      // update ans with max tiles that can be cover in carpet
      ans = max(ans, tsum);

    }
    return ans;
  }
};