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
        char buffer[4];
        int count = 0;
        while (count < n) {
            int t = read4(buffer);
            int r = std::min(n - count, 4);
            int c = std::min(t, r);

            for (int i = 0; i < c; ++i) {
                *(buf++) = buffer[i];
            }

            count += c;

            if (t < 4) {
                break;
            }
        }
        return count;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
