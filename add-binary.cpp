class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.size() >= b.size()) {
        } else {
            string t = a;
            a = b;
            b = t;
        }

        string ans("");

        int la = a.size();
        int lb = b.size();

        int temp = 0;
        for (int i = 0; i < la; ++i) {
            int index_a = la - 1 - i;
            int index_b = lb - 1 - i;

            temp += a[index_a] - '0';
            if (index_b >= 0) {
                temp += b[index_b] - '0';
            }

            char bit = '0' + temp % 2;
            temp /= 2;
            ans = bit + ans;
        }

        if (temp) {
            ans = '1' + ans;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
