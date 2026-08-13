class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Return empty string if provided t is empty
        if not t:
            return ""

        # Create a frequency map for t
        freq_t = {}

        for c in t:
            freq_t[c] = freq_t.get(c, 0) + 1

        window = {}
        matched = 0
        target = len(freq_t)
        result_start_idx = -1
        s_size = len(s)
        result_length = s_size + 1
        L = 0

        for R in range(s_size):
            cR = s[R]
            window[cR] = window.get(cR, 0) + 1

            if freq_t.get(cR, 0) > 0 and window.get(cR, 0) == freq_t.get(cR, 0):
                matched += 1

            while matched == target:
                window_length = R - L + 1

                if window_length < result_length:
                    result_start_idx = L
                    result_length = window_length
                cL = s[L]

                window[cL] -= 1
                L += 1

                if freq_t.get(cL, 0) > 0 and window.get(cL, 0) < freq_t.get(cL, 0):
                    matched -= 1

        # Return empty string if there's not a valid window,
        # otherwise, return the string from minimum window
        return (
            s[result_start_idx : result_start_idx + result_length]
            if result_length != s_size + 1
            else ""
        )