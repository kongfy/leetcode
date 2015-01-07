// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n)
    {
        int count = 0;

        if (n > 0 && _used < _len) {
            while (_used < _len) {
                *(buf++) = _buffer[_used];
                ++_used;
                if (++count == n) {
                    break;
                }
            }
        }

        while (count < n) {
            _len = read4(_buffer);
            int r = std::min(n - count, 4);
            _used = std::min(_len, r);

            for (int i = 0; i < _used; ++i) {
                *(buf++) = _buffer[i];
            }

            count += _used;

            if (_len < 4) {
                break;
            }
        }
        return count;
    }

private:
    char _buffer[4];
    int _len = 0;
    int _used = 0;
};
