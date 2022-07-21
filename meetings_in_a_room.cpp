/*
You are given the schedule of N meetings with their start time Start[i] and end time End[i]. But you have only 1 meeting room. So, you need to tell the meeting numbers you can organize in the given room, such that the number of meetings organized is maximum.

Sample Input 1:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
3
1 1 1
4 5 9
Sample Output 1:
1 2 4 5
1
Explanation For Sample Input 1:
For test case 1: 
You can organize a maximum of 4 meetings. Meeting number 1 from 1 to 2, Meeting number 2 from 3 to 4, Meeting number 4 from 5 to 7, and Meeting number 5 from 8 to 9.

For test case 2:
As all meetings have the same start time, you can organize only 1 meeting in the room.
*/
#include<bits/stdc++.h>
struct meeting{
    int s_time;
    int e_time;
    int m_no;
};
bool comp(meeting m1,meeting m2)
{
    if(m1.e_time<m2.e_time)
        return true;
    else if(m1.e_time==m2.e_time and m1.m_no<m2.m_no)
        return true;
    else
        return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<meeting>meetings;
    int n=start.size();
    for(int i=0;i<n;i++)
    {
        struct meeting temp;
        temp.s_time=start[i];
        temp.e_time=end[i];
        temp.m_no=i+1;
        meetings.push_back(temp);
    }
    sort(meetings.begin(),meetings.end(),comp);
    int last_meeting=meetings[0].e_time;
    vector<int>ans;
    ans.push_back(meetings[0].m_no);
    for(int i=1;i<n;i++)
    {
        if(last_meeting<meetings[i].s_time)
        {
            last_meeting=meetings[i].e_time;
            ans.push_back(meetings[i].m_no);
        }
    }
    return ans;
}