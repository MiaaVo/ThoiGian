#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_SIZE 100

// Bài 4a
struct monthDay // struct lưu tháng và ngày 
{
    int ngay;
    int thang;
};

// Nhập tháng ngày
void setDM(monthDay &MD)
{
    do
    {
        cout << "Nhap thang: "; // Nhập tháng trước để xét nếu tháng đó chỉ có 30 ngày hoặc 29 ngày
        cin >> MD.thang;
    } while ((MD.thang < 0) || (MD.thang > 12));
    switch (MD.thang)
    {
    case 2:
        do
        {
            cout << "Nhap ngay: ";
            cin >> MD.ngay;
        } while ((MD.ngay < 0) || (MD.ngay > 29));
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        do
        {
            cout << "Nhap ngay: ";
            cin >> MD.ngay;
        } while ((MD.ngay < 0) || (MD.ngay > 30));
        break;
    default:
        do
        {
            cout << "Nhap ngay: ";
            cin >> MD.ngay;
        } while ((MD.ngay < 0) || (MD.ngay > 31));
    }
}

// Nhập mảng ngày
void setArrDM(monthDay MD[], int &n)
{
    do
    {
        cout << "Nhap so luot muon nhap: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ngay thang lan " << i + 1 << endl;
        setDM(MD[i]);
    }
}

// Sắp xếp theo thứ tự ngày tháng tăng dần
void sapXep(monthDay MD[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (MD[i].thang > MD[j].thang) // Nếu thắng trước lớn hơn tháng sau thì đổi
            {
                swap(MD[i], MD[j]);
            }
            if (MD[i].thang == MD[j].thang) // Nếu 2 tháng bằng nhau thì so sánh sang ngày
            {
                if (MD[i].ngay > MD[j].ngay) // Nếu ngày trước lớn hơn ngày sau thì đổi
                {
                    swap(MD[i], MD[j]);
                }
            }
        }
    }
}

// Xuất ngày tháng
void printMonthDay(monthDay MD) // MD là month day
{
    cout << setfill('0') << setw(2) << MD.ngay << "/" << setfill('0') << setw(2) << MD.thang << endl;
}

// Xuất mảng ngày tháng
void printArrMonthDay(monthDay MD[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printMonthDay(MD[i]);
    }
}

// Bài 4b
struct Time // Struct lưu thời gian
{
    int hour;
    int min;
    int sec;
};

// Nhập giờ phút giây
void setTime(Time &HMS) // HMS là hour minute second
{
    do
    {
        cout << "Nhap gio (0h - 23h): "; // Nếu nhập lố thì yêu cầu nhập lại
        cin >> HMS.hour;
    } while ((HMS.hour < 0) || (HMS.hour > 23));
    do
    {
        cout << "Nhap phut: "; // Nếu nhập lố thì yêu cầu nhập lại
        cin >> HMS.min;
    } while ((HMS.min < 0) || (HMS.min > 60));
    do
    {
        cout << "Nhap giay: "; // Nếu nhập lố thì yêu cầu nhập lại
        cin >> HMS.sec;
    } while ((HMS.sec < 0) || (HMS.sec > 60));
}

// Nhập mảng giờ phút giây
void setArrTime(Time HMS[], int &n)
{
    do
    {
        cout << "Nhap so lan can nhap: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        setTime(HMS[i]);
    }
}

// Thay đổi đơn vị nếu 60 phút thì tăng lên 1 giờ hoặc 60 giây tăng lên 1 phút
void change(Time &HMS)
{
    if ((HMS.sec == 60 && HMS.min == 60))
    {
        HMS.sec = 0;
        HMS.min = 1;
        HMS.hour++;
    }
    if (HMS.sec == 60)
    {
        HMS.sec = 0;
        HMS.min++;
    }
    if (HMS.min >= 60)
    {
        HMS.min = 0;
        HMS.hour++;
    }
    if (HMS.hour == 24)
    {
        HMS.hour = 0;
    }
}

// So sánh giờ phút giây
void soSanhHMS(Time HMS[], int n)
{
    // Thay đổi dơn vị thời gian phù hợp
    for (int i = 0; i < n; i++) 
    {
        change(HMS[i]); 
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (HMS[i].hour > HMS[j].hour) // Nếu giờ trước lớn hơn giờ sau thì đổi
            {
                swap(HMS[i], HMS[j]);
            }
            if (HMS[i].hour == HMS[j].hour) // Nếu 2 giờ bằng nhau thì so sánh phút
            {
                if (HMS[i].min > HMS[j].min) // Nếu phút trước lớn hơn phút sau thì đổi
                {
                    swap(HMS[i], HMS[j]);
                }
                if (HMS[i].min == HMS[j].min) // Nếu 2 phút bằng nhau thì so sánh giây
                {
                    if (HMS[i].sec > HMS[j].sec) // Nếu giây trước lớn hơn giây sau thì đổi
                    {
                        swap(HMS[i], HMS[j]);
                    }
                }
            }
        }
    }
}

// Xuat gio thang nam
void printTime(Time HMS)
{
    cout << setfill('0') << setw(2) << HMS.hour << ":" << setfill('0') << setw(2) << HMS.min << ":" << setfill('0') << setw(2) << HMS.sec << endl;
}

// Xuat mang gio phut giay
void printArrTime(Time HMS[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printTime(HMS[i]);
    }
}

// Bai 4c
struct Test
{
    int Y;     // Nam
    int Month; // Thang
    int D;     // Ngay
    int H;     // Gio
    int Min;   // Phut
};

// Nhap nam thang ngay gio phut
void setTest(Test &YMDHM) // YMDHM là year month day hour minute
{
    cout << "Nhap nam: ";
    cin >> YMDHM.Y;
    do
    {
        cout << "Nhap thang: ";
        cin >> YMDHM.Month;
    } while (YMDHM.Month < 1 || YMDHM.Month > 12); // Nhập sai tháng sẽ nhập lại
    switch (YMDHM.Month)
    {
    case 2:
        if ((YMDHM.Y % 4 == 0 && YMDHM.Y % 100 != 0) || (YMDHM.Y % 400 == 0)) // Kiểm tra năm nhuận 
        {
            do
            {
                cout << "Nhap ngay: ";
                cin >> YMDHM.D;
            } while ((YMDHM.D < 0) || (YMDHM.D > 29)); // Nếu nhuận tháng 2 có 29 ngày
            break;
        }
        else
        {
            do
            {
                cout << "Nhap ngay: ";
                cin >> YMDHM.D;
            } while ((YMDHM.D < 0) || (YMDHM.D > 28)); // Nếu không nhuận có 28 ngày
            break;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        do
        {
            cout << "Nhap ngay: ";
            cin >> YMDHM.D;
        } while ((YMDHM.D < 0) || (YMDHM.D > 30));
        break;
    default:
        do
        {
            cout << "Nhap ngay: ";
            cin >> YMDHM.D;
        } while ((YMDHM.D < 0) || (YMDHM.D > 31));
    }
    do
    {
        cout << "Nhap gio (0h - 23h): ";
        cin >> YMDHM.H;
    } while ((YMDHM.H < 0) || (YMDHM.H > 23));
    do
    {
        cout << "Nhap phut: ";
        cin >> YMDHM.Min;
    } while ((YMDHM.Min < 0) || (YMDHM.Min > 60));
}

// Nhap day ngay thang nam gio phut
void setArrTest(Test YMDHM[], int &n)
{
    do
    {
        cout << "Nhap so luot muon nhap: ";
        cin >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ngay thang lan " << i + 1 << endl;
        setTest(YMDHM[i]);
    }
}

// Thay doi neu ngay thang can tang len
void thayDoiDV(Test &YMDHM) // Thay đổi đơn vị ngày giờ nếu là 60 phút hoặc 24 giờ
{
    if (YMDHM.Min == 60) // YMDHMlà year month day hour minute
    {
        YMDHM.Min = 0;
        YMDHM.H++;
    }
    if (YMDHM.H == 24)
    {
        YMDHM.H = 0;
        YMDHM.D++;
    }
    switch (YMDHM.Month)
    {
    case 2:
        if ((YMDHM.Y % 4 == 0 && YMDHM.Y % 100 != 0) || (YMDHM.Y % 400 == 0))
        {
            if (YMDHM.D == 30)
            {
                YMDHM.Month++;
                YMDHM.D = 1;
            }
        }
        else
        {
            if (YMDHM.D == 29)
            {
                YMDHM.Month++;
                YMDHM.D = 1;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (YMDHM.D == 31)
        {
            YMDHM.D = 1;
            YMDHM.Month++;
        }
        break;
    case 12:
        if (YMDHM.D == 32)
        {
            YMDHM.D = 1;
            YMDHM.Month = 1;
            YMDHM.Y++;
        }
    default:
        if (YMDHM.D == 32)
        {
            YMDHM.D = 1;
            YMDHM.Month++;
        }
    }
}

// Sap xep ngay thang nam gio phut theo thu tu tang dan
void test(Test YMDHM[], int n)
{
    for (int i = 0; i < n; i++)
    {
        thayDoiDV(YMDHM[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (YMDHM[i].Y > YMDHM[j].Y)
            {
                swap(YMDHM[i], YMDHM[j]);
            }
            if (YMDHM[i].Y == YMDHM[j].Y)
            {
                if (YMDHM[i].Month > YMDHM[j].Month)
                {
                    swap(YMDHM[i], YMDHM[j]);
                }
                if (YMDHM[i].Month == YMDHM[j].Month)
                {
                    if (YMDHM[i].D > YMDHM[j].D)
                    {
                        swap(YMDHM[i], YMDHM[j]);
                    }
                    if (YMDHM[i].D == YMDHM[j].D)
                    {
                        if (YMDHM[i].H > YMDHM[j].H)
                        {
                            swap(YMDHM[i], YMDHM[j]);
                        }
                        if (YMDHM[i].H == YMDHM[j].H)
                        {
                            if (YMDHM[i].Min > YMDHM[j].Min)
                            {
                                swap(YMDHM[i], YMDHM[j]);
                            }
                        }
                    }
                }
            }
        }
    }
}

// Xuat nam thang ngay gio phut
void printTest(Test YMDHM)
{
    cout << setfill('0') << setw(2) << YMDHM.Min << ":" << setfill('0') << setw(2) << YMDHM.H << " " << setfill('0') << setw(2) << YMDHM.D << "/" << setfill('0') << setw(2) << YMDHM.Month << "/" << setfill('0') << setw(2) << YMDHM.Y << endl;
}

// Xuat mang nam thang ngay gio phut
void printArrTest(Test YMDHM[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printTest(YMDHM[i]);
    }
}

int main()
{
    // Bai 4a
    monthDay MD[MAX_SIZE];
    int n;
    setArrDM(MD, n);
    sapXep(MD, n);
    cout << "Sap xep lai thu tu ngay thang: " << endl;
    printArrMonthDay(MD, n);

    // Bai 4b
    Time HMS[MAX_SIZE];
    int m;
    setArrTime(HMS, m);
    soSanhHMS(HMS, m);
    cout << "Sap xep lai gio phut giay: " << endl;
    printArrTime(HMS, m);

    // Bai 4c
    Test YMDHM[MAX_SIZE];
    int l;
    setArrTest(YMDHM, l);
    test(YMDHM, l);
    cout << "Sap xep lai ngay thang nam gio phut:\n";
    printArrTest(YMDHM, l);

    return 0;
}