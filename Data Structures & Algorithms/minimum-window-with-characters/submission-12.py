class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Return empty string if provided t is empty
        if not t:
            return ""

        # Create a frequency map for t
        freq_t = defaultdict(int)

        for c in t:
            freq_t[c] += 1

        window = defaultdict(int)
        matched = 0
        target = len(freq_t)
        result_start_idx = -1
        s_size = len(s)
        result_length = s_size + 1
        L = 0

        # Extend the window by moving its right pointer
        for R in range(s_size):
            cR = s[R]
            window[cR] += 1

            # Increment matched if cR is in t and currnet window contains enough cR
            if freq_t[cR] > 0 and window[cR] == freq_t[cR]:
                matched += 1

            # Exit the while loop when this is not a valid window
            while matched == target:
                # Update result_start_idx and result_length if window_length is smaller than
                # result_length
                # Note that this is for avoiding using string slicing in a while loop
                window_length = R - L + 1

                if window_length < result_length:
                    result_start_idx = L
                    result_length = window_length

                # Shrink the window by moving its left pointer;
                # Decrement matched if cL is in freqT and window[cL] is smaller than freqT[cL],
                # which freq[cL] is the target.
                #
                # Note that we have to have the second condition because window[cL] might be larger
                # than freq[cL] and we shouldn't decrement matched when that happen
                cL = s[L]

                window[cL] -= 1
                L += 1

                if freq_t[cL] > 0 and window[cL] < freq_t[cL]:
                    matched -= 1

        # Return empty string if there's not a valid window,
        # otherwise, return the string from minimum window
        return (
            s[result_start_idx : result_start_idx + result_length]
            if result_length != s_size + 1
            else ""
        )
