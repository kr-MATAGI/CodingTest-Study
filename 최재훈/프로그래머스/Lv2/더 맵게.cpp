/*
* Lv2 - 더 맵게
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define K_MAX   1000000000
#define SCOVILLE_MAX    1000000

void SwapElement(vector<int>& srcVec, int lhsIdx, int rhsIdx)
{
    const int temp = srcVec[lhsIdx];
    srcVec[lhsIdx] = srcVec[rhsIdx];
    srcVec[rhsIdx] = temp;
}

void InsertToMinHeap(vector<int>& minHeap, int element)
{
    minHeap.push_back(element);
    int currIdx = minHeap.size() - 1;

    while (0 < currIdx)
    {
        // compare
        int parentElem = minHeap[currIdx / 2];
        if (parentElem > element)
        {
            // swap
            SwapElement(minHeap, currIdx, currIdx / 2);
        }
        else
            break;

        currIdx /= 2;
    }
}

void DeleteFromMinHeap(vector<int>& minHeap)
{
    // swap root and last node, delete last node
    SwapElement(minHeap, 1, minHeap.size() - 1);
    minHeap.pop_back();

    // heapify
    const int lastIdx = minHeap.size() - 1;
    int currIdx = 1;
    while (lastIdx / 2 >= currIdx)
    { 
        const int leftChildIdx = currIdx * 2;
        const int rightChildIdx = (currIdx * 2) + 1;

        int minIdx = -1;
        if (leftChildIdx <= lastIdx && rightChildIdx <= lastIdx)
        {
            if (minHeap[leftChildIdx] > minHeap[rightChildIdx])
            {
                minIdx = rightChildIdx;
            }
            else
            {
                minIdx = leftChildIdx;
            }
        }
        else if (rightChildIdx > lastIdx)
        {
            minIdx = leftChildIdx;
        }

        if (minHeap[currIdx] > minHeap[minIdx])
        {
            SwapElement(minHeap, currIdx, minIdx);
            currIdx = minIdx;
        }
        else
            break;
    }
}

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    // init - heapify
    vector<int> minHeap;
    minHeap.push_back(-1); // index + 1 

    auto scovIter = scoville.begin();
    while (scovIter != scoville.end())
    {
        InsertToMinHeap(minHeap, *scovIter);
        ++scovIter;
    }

    // Check scoville
    while (K > minHeap[1] && 2 < minHeap.size())
    {
        answer++;

        const int topElement = minHeap[1];
        DeleteFromMinHeap(minHeap);

        const int nextElement = minHeap[1];
        DeleteFromMinHeap(minHeap);

        const int mixScoville = topElement + (nextElement * 2);
        InsertToMinHeap(minHeap, mixScoville);

        for (auto a : minHeap)
        {
            printf("%d ", a);
        }
        printf("(loop: %d) %d + %d = %d\n", answer, topElement, nextElement * 2, mixScoville);
    }

    if (2 == minHeap.size() && K > minHeap[1])
        return -1;

    return answer;
}

int main()
{
    vector<int> scoville = { 0,0,0,1};
    int K = 3;

    const int answer = solution(scoville, K);
    printf("answer: %d\n", answer);
}