#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int compare(string str1,string str2)
{
    if(str1.length()>str2.length()) return 1;
    else if(str1.length()<str2.length())  return -1;
    else return str1.compare(str2);
}

//高精度加法
string add(string str1,string str2)//高精度加法
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    //前面补0，弄成长度相同
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}

//高精度乘法
string mul(string str1,string str2)
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    string tempstr;
    for(int i=len2-1;i>=0;i--)
    {
        tempstr="";
        int temp=str2[i]-'0';
        int t=0;
        int cf=0;
        if(temp!=0)
        {
            for(int j=1;j<=len2-1-i;j++)
              tempstr+="0";
            for(int j=len1-1;j>=0;j--)
            {
                t=(temp*(str1[j]-'0')+cf)%10;
                cf=(temp*(str1[j]-'0')+cf)/10;
                tempstr=char(t+'0')+tempstr;
            }
            if(cf!=0) tempstr=char(cf+'0')+tempstr;
        }
        str=add(str,tempstr);
    }
    str.erase(0,str.find_first_not_of('0'));
    return str;
}

int main()
{
     auto start = high_resolution_clock::now(); // 记录开始时间
     mpz_class p1("132872155597415695517204800320225475210600169996924038794570770032541953128245570479121311561005386592327193418866898729125260912230933795197781659801533135422858199544978362491253569254219209862953778212147146534610916355487245132267952621363498618513476571366956589947518823812787667764674357785144657739751"), p2("99044218653805280864724545574863958746312617659428843725163579555322474623896413044622795368965753124712683459962275442426624060860602983907649118564110909438124241103744451786095350614131111954127746326053353496658459213979532010236003976206666179135815375217530819181185102017197901876055869337631073018837");
     mpz_class n = p1 * p2;
     string str1 = "16166392929715882314249214437276545792712394133361090522908954536376469330942458115273697678762316818139204858869377207505725336108241185870077056699177864285686686456445249265624061325817479777056914575451404894384557435546564423919825745922738689769097117273149997322479649170353428672323455777784407558577734977811384383208003787435954785863027418138765535619385113231437810710170809371019013636908862039104359971684357506280693120486100115346221478615604249398628999152337028957452843481796504463327483235778263079606667296973353343312915920670393544213996299017456710805644105850259166736242332994152602810712064";
     string str2 = "16284741340621562272625855831400092980067536110911318125565681875588595753570148145400152273775218112561893034995800173885708684103177065708071764288483705166255403048366517561858498085157285631940200919341971548076977328925382611503426227225247757776191532480127669338017567539096865192618649451121043045829402144559637563172923288076042302597017369955301154474578269258022274917419497580177278744060464250225182519061256170309102294135339501256515925750418336143860543802061311746306817445792086487217142703097284039193831772061006003220038291978375927407363768263558150855465805014609526668425659004358697999663104";
     string r=mul(str1,str2);
     mpz_class ad(r);
     mpz_class res(ad % n);
     cout<<res<<endl;
     auto stop = high_resolution_clock::now(); // 记录结束时间
     auto duration = duration_cast<nanoseconds>(stop - start); // 计算时间差
     cout << "Time:" << duration.count() << " ns" << endl; // 输出时间差
     system("pause");
     return 0;
}
