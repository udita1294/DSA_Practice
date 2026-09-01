class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        int litterCount = 0;

        // litterId[i][j] tells us which bit belongs to this L cell
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        // Find S and assign IDs to all L cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        /*
            mask:
            bit = 1 -> litter still needs to be collected
            bit = 0 -> litter already collected

            Initially all litter is uncollected.
        */
        int fullMask = (1 << litterCount) - 1;

        /*
            visited[row][col][energy][mask]
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // row, col, remaining energy, mask
        queue<array<int, 4>> q;

        q.push({sx, sy, energy, fullMask});

        visited[sx][sy][energy][fullMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, curEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // No energy -> cannot make another move
                if (curEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int nextEnergy;

                    // Reset cell
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }
                    else {
                        nextEnergy = curEnergy - 1;
                    }

                    int nextMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {

                        int id = litterId[nr][nc];

                        nextMask &= ~(1 << id);
                    }

                    // Avoid visiting identical states
                    if (!visited[nr][nc][nextEnergy][nextMask]) {

                        visited[nr][nc][nextEnergy][nextMask] = true;

                        q.push({
                            nr,
                            nc,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};