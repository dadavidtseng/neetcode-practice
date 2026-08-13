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

        for R in range(s_size):
            cR = s[R]
            window[cR] += 1

            if freq_t[cR] > 0 and window[cR] == freq_t[cR]:
                matched += 1

            while matched == target:
                window_length = R - L + 1

                if window_length < result_length:
                    result_start_idx = L
                    result_length = window_length
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
