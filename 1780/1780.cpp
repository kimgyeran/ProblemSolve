#include <iostream>
#include <queue>

using namespace std;

class Paper
{
public:
    static int ORIGINAL_SIZE;
    int Start_idx;
    int Size;
    Paper(int start_idx, int size)
    {
        Start_idx = start_idx;
        Size = size;
    }
};
int Paper::ORIGINAL_SIZE;
void split_paper(Paper paper, queue<Paper> &waiting_queue);
bool is_single_color(const Paper &paper, int arr[]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int paper_mat[n * n];
    Paper::ORIGINAL_SIZE = n;
    Paper origin = Paper(0, n);
    for (size_t i = 0; i < n * n; i++)
    {
        cin >> paper_mat[i];
    }
    int result[3] = {
        0,
    };
    queue<Paper> waiting_queue;
    waiting_queue.push(origin);
    while (!waiting_queue.empty())
    {
        Paper &p = waiting_queue.front();
        if (is_single_color(p, paper_mat))
        {
            switch (paper_mat[p.Start_idx])
            {
            case 1:
                result[2]++;
                break;

            case 0:
                result[1]++;
                break;

            case -1:
                result[0]++;
                break;
            default:
                break;
            }
        }
        else
        {
            split_paper(p, waiting_queue);
        }
        waiting_queue.pop();
    }
    cout << result[0] << '\n'
         << result[1] << '\n'
         << result[2];
    return 0;
}

bool is_single_color(const Paper &paper, int arr[])
{
    int first = arr[paper.Start_idx];
    for (size_t i = 0; i < paper.Size; i++)
    {
        for (size_t j = 0; j < paper.Size; j++)
        {
            if (arr[paper.Start_idx + i + Paper::ORIGINAL_SIZE * j] != first)
                return false;
        }
    }
    return true;
}

void split_paper(Paper paper, queue<Paper> &waiting_queue)
{
    int size = paper.Size;
    int start_idx = paper.Start_idx;
    if (paper.Size == 1)
        return;
    int divided_size = size / 3;
    int vertical_size = paper.ORIGINAL_SIZE * divided_size;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            Paper p = Paper(start_idx + divided_size * j + vertical_size * i, divided_size);
            waiting_queue.push(p);
        }
    }
}