#include<iostream>

using namespace std;

class box
{
    //global class variables initialized
public:
    int l,b,h,v;
    void input();
    int volume();
};
//user interfaced input
void box::input()
{
    cout<<"Enter length"<<endl;
    cin>>l;
    cout<<"Enter breadth"<<endl;
    cin>>b;
    cout<<"Enter height"<<endl;
    cin>>h;
    v=l*b*h;
}
//just to get volume, if v was private
int box::volume()
{
    return v;
}
int main()
{
    int n, max_volume=0, max_box=0;
    cout<<"Enter number of boxes\n";
    cin>>n;
    box b[n];
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter details for box "<<i<<"\n";
        b[i].input();
        if(b[i].volume()> max_volume)
        {
            max_box=i;
            max_volume = b[i].volume();
        }
    }
    cout<<"Max Volume ("<<max_volume<<") was of the box number "<<max_box<<endl;
    return 0;
}
