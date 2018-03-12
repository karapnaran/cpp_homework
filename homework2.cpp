#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

template<typename Iter>
unsigned int count_even_elements(Iter beg,Iter end)
{
  if(is_integral<typename iterator_traits<Iter>::value_type>::value==false){return end;}
  unsigned int res=0;
  while(beg != end)
  {
    if(*beg%2==0)++res;
    ++beg;
  }
  return res;
}

template<typename Iter,typename T>
Iter closest_to(Iter beg,Iter end,T R)
{
    auto res=*beg;
    Iter ans=beg;
    while(beg != end)
    {
      if(abs(*beg-R)<abs(res-R))
      {
        res=*beg;
        ans=beg;
      }
      ++beg;
    }
    return ans;
}

template<typename Iter>
Iter max_odd(Iter b, Iter e)
{
    if(is_integral<typename iterator_traits<Iter>::value_type>::value==false){return e;}
    auto res = *b;
    Iter ans=b;
    while (b != e)
    {
        if (*b % 2 && *b>res)
        {
          res = *b;
          ans=b;
        }
        ++b;
    }
    return ans;
}

template<typename Iter>
unsigned int count_leftmecright(Iter beg,Iter end)
{
  unsigned int res=0;
  while(beg != end)
  {
    if(*beg<*++beg)++res;
  }
  return res;
}

template<typename Iter>
Iter min_even(Iter b, Iter e)
{
    if(is_integral<typename iterator_traits<Iter>::value_type>::value==false){return e;}
    auto res = *b;
    Iter ans=b;
    while (b != e)
    {
        if (*b % 2==0 && *b<res)
        {
          res = *b;
          ans=b;
        }
        ++b;
    }
    return ans;
}

template<typename Iter>
double modul_mijin(Iter beg,Iter end)
{
  double res=0.0;
  unsigned int qanak=0;
  while(beg != end)
  {
    res+=abs(*beg);
    ++beg;
    ++qanak;
  }
  res/=qanak;
  return res;
}

template<typename Iter>
double mijin(Iter beg,Iter end)
{
  double res=0.0;
  unsigned int qanak=0;
  while(beg != end)
  {
    res+=*beg;
    ++beg;
    ++qanak;
  }
  res/=qanak;
  return res;
}

template<typename Iter>
unsigned int count_mijinicpoqr(Iter beg,Iter end)
{
  int avg=mijin(beg,end);
  unsigned int res=0;
  while(beg != end)
  {
    if(*beg<avg)++res;
    ++beg;
  }
  return res;
}

template<typename Iter>
unsigned int count_min(Iter beg,Iter end)
{
  int minn=*min_element(beg,end);
  unsigned int res=0;
  while(beg != end)
  {
    if(*beg==minn)++res;
    ++beg;
  }
  return res;
}

int main()
{
    int a[6]={1,-2,-3,8,5,7};
    cout<<count_even_elements(a,a+6)<<endl;
    cout<<*max_odd(a,a+6)<<endl;
    cout<<*closest_to(a,a+6,4)<<endl;
    cout<<count_leftmecright(a,a+6)<<endl;
    cout<<*min_even(a,a+6)<<endl;
    cout<<modul_mijin(a,a+6)<<endl;
    cout<<count_mijinicpoqr(a,a+6)<<endl;
    cout<<count_min(a,a+6)<<endl;
}
