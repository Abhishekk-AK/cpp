//input-output
class Solution {
public:
    int x;
    void printNumber() {
        cin>>x;
        cout<<x;
    }
};

//if-else
class Solution {
public:
    void studentGrade(int marks) {
        if(marks>=90)
            cout<<"Grade A";
        else if(marks>=70)
            cout<<"Grade B";
        else if(marks>=50)
            cout<<"Grade C";
        else if(marks>=35)
            cout<<"Grade D";
        else
            cout<<"Fail";
    }
};

//switch-case
class Solution {
public:
    void whichWeekDay(int day) {
        switch(day) {
            case 1:
                cout<<"Monday"<<endl;
                break;
            case 2: 
                cout<<"Tuesday"<<endl;
                break;
            case 3: 
                cout<<"Wednesday"<<endl;
                break;
            case 4:
                cout<<"Thursday"<<endl;
                break;
            case 5:
                cout<<"Friday"<<endl;
                break;
            case 6:
                cout<<"Saturday"<<endl;
                break;
            case 7:
                cout<<"Sunday"<<endl;
                break;
            default:
                cout<<"Invalid"<<endl;
        }
    }
};
