int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];

    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char ch = s[right];

        if (lastIndex[ch] >= left) {
            left = lastIndex[ch] + 1;
        }

        lastIndex[ch] = right;

        int currentLength = right - left + 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}