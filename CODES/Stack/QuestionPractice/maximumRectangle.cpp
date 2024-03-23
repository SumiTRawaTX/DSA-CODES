   vector<int> prevSmallerElement(vector<int> & input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        // left to right -> prev smaller

        for(int i = 0; i < input.size(); i++) {
            int curr = input[i];

            while(s.top() != -1 && input[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& input) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(input.size());

        for(int i = input.size() - 1; i >= 0; i--) {
            int curr = input[i];

            while(s.top() != -1 && input[s.top()] >= curr) {
                s.pop();        
            }

            ans[i] = s.top();

            s.push(i);
        }

        return ans;
    }

    int getRectangularAreaHistogram(vector<int>& height) {
        // step 1 prev smaller output
        vector<int> prev = prevSmallerElement(height);

        // step 2- nextSmaller
        vector<int> next = nextSmaller(height);

        int maxArea = INT_MIN;
        int size = height.size();

        for(int i = 0; i < height.size(); i++) {
            int length = height[i];

            if(next[i] == -1) {
                next[i] = size;
            }

            int width = next[i] - prev[i] - 1;

            int area = length * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> heights(m, vector<int>(n, 0));
        
        // Convert matrix to height matrix
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0')
                    heights[i][j] = 0;
                else
                    heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            maxArea = max(maxArea, getRectangularAreaHistogram(heights[i]));
        }
        
        return maxArea;