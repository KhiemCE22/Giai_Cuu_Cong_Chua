#include "knight.h"
bool Athur(int maxHP){
    if (maxHP==999) return 1;
    else return 0;
}
bool is_prime(int n){
    int count=0;
    if (n<=1) return false;
    if (n>1){
        for (int i=2;i<=n/2;i++){
            if(n%i==0) count++;
        }
    }
    if (count==0) return true;
    else return false;
}
bool lancelot(int maxHP){
    if (is_prime(maxHP)==1) return 1;
    else return 0;
}
void checkTiny(int & tiny,int &HP,int maxHP, int & remedy){
      if (tiny>0)// Phải đặt vào trong từng hàm
    {
        tiny--;
        if (tiny==0) {
            HP=HP*5;
            if (HP>maxHP) HP=maxHP;
            }
    }  
}
void checkFrog(int & frog, int &level, int level_before){
    if (frog>0)
    {
        frog--;
        if (frog==0){
            level=level_before;
        }
    }
}
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void sukien_0(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int & tiny){
        rescue=1;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
void healing(int & HP, int & level, int maxHP, int & rescue , int & phoenixdown){
    if ((HP<=0) && (phoenixdown>0)) {
        HP=maxHP;
        phoenixdown--;
    }
    if (HP<0 && phoenixdown==0){
        rescue=0;
    }
}
void sukien_1_5(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int & tiny,int & frog, int level_before){
    float basedame;
    switch (masukien[stt_su_kien])
    {
        case 1:
        //MadBear[1]
        {   
            basedame=1;
            break;
        }
        case 2:
        //Bandit
        {
            basedame=1.5;  
            break;
        }  
        case 3:
        //LordLupin
        {
            basedame=4.5;  
            break;
        }  
        case 4:
        //Elf
        {
            basedame=7.5;  
            break;
        }  
        case 5:
        {   //Troll
            basedame=9.5;
            break;
        }
 
    }
    int b = stt_su_kien%10;
    int levelO= stt_su_kien > 6?(b > 5?b : 5) : b;
    float damage = basedame*levelO*10;
    if (lancelot(maxHP)==0 && Athur(maxHP)==0){
    if (level>levelO) {
        if(level<10) level++;
        }
    else if (level<levelO) {
        HP=HP-damage;
        healing(HP,level,maxHP,rescue,phoenixdown);
        
    }          
    }
 
    checkTiny(tiny,HP,maxHP,remedy);
    checkFrog(frog, level, level_before);
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    

}

bool Shaman(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP, int & tiny,int &frog, int level_before){
    bool check;
    int b = stt_su_kien%10;
    int levelO= stt_su_kien > 6?(b > 5?b : 5) : b;
    if (lancelot(maxHP)==0 && Athur(maxHP)==0){
    if (level>levelO){
        if (level<10) level+=2;
        if (level>10) level=10;
        check=1;
    }
    else if(level<levelO){
        //trạng thái tí hon
        if (remedy==0) {
        if(HP<5) HP=1;
        else HP=HP/5;
        }
        else remedy--;
        check=0;
    }
    }

    checkFrog(frog,level,level_before);
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
     // 3 sự kiện tiếp theo vẫn ở trạng thái tí hon, đến sự kiện thứ tư thì HP=HP*5;
    return check;
}
bool SirenVajsh(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int & tiny,int & frog, int level_before){
    bool check;
    int b = stt_su_kien%10;
    int levelO= stt_su_kien > 6?(b > 5?b : 5) : b;
    if (lancelot(maxHP)==0 && Athur(maxHP)==0){
        if (level>levelO){
        if (level<10) level+=2;
        if (level>10) level=10;
        check=1;
    }
    else if(level<levelO){
        //biến thành ếch
        if (maidenkiss==0) 
        level=1;
        else maidenkiss--;
        check=0;
    }
    }
    checkTiny(tiny,HP,maxHP,remedy);
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
     // 3 sự kiện tiếp theo vẫn ở trạng thái tiếp theo, đến sự kiện thứ tư thì level trở lại trước lúc biến thành ếch; tạo biến level lúc biến thành ếch để lưu lại ở đoạn main
     return check;
}

void MushMarrio(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int &tiny,int & frog, int level_before){
    // Mã sự kiện 11
    int n1=((level+phoenixdown)%5+1)*3;
    int s1=0;
    int start=99;
    for (int i=1;i<=n1;i++){
        s1+=start;
        start-=2;
    }
    HP = HP + (s1%100);
    int nearest=0;
    int i=2;
    int data;
    while(i<HP){
        if(is_prime(i)==1) {
            if (((HP-i)<=nearest)) nearest=HP-i;
        }
        i++;
    }

    while(is_prime(i)!=1){    
        i++;
        data=i;
    }
    HP=data;
    if (HP>maxHP) HP=maxHP;  
    checkTiny(tiny,HP,maxHP,remedy);
    checkFrog(frog, level, level_before);    
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
}

void Fibonaci(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int &tiny,int & frog, int level_before){
    if (Athur(maxHP)==0){
    int f0 = 0;
    int f1 = 1;
    int fn=1;
    int data;
    while(fn <= HP) {
        data=fn;
        f0 = f1;
        f1 = fn;
        fn = f0 + f1;
    }
    if (HP>1) HP=data;        
    }
    checkTiny(tiny,HP,maxHP,remedy);
    checkFrog(frog, level, level_before);

    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    
}
int checkchuso(int n){
    int count=1;
    while(n/10){
        n=n/10;
        count++;
    }
    return count;
}
int Nam1(int arr[],int n2){
    int max=arr[0];
    int min=arr[0];
    int maxi;
    int mini;
    for (int i=0;i<n2;i++){
        if (max<=arr[i]) maxi=i;
        if (min>=arr[i]) mini=i;
    }
    return maxi+mini;
}
bool checkDay_dinh_nui(int arr[],int n2){
    int max=arr[0];
    int pos;
    bool flag;
    for (int i=0;i<n2;i++){
        if (max<arr[i]) {
            max=arr[i];
            pos=i;
        }
    }
    
    if(pos==0){
        int i=0;
        while(i<n2-1){
            if (arr[i]>arr[i+1]) flag=1;
            else {
                flag=0;
                break;
            }
            i++;
        }
    }
    else if(pos==n2-1){
        int i=0;
        while(i<n2-1){
            if (arr[i]<arr[i+1]) flag=1;
            else {
                flag=0;
                break;
            }
            i++;
        }        
    }
    else {
        int i=0;
        while(i<pos){
            if (arr[i]<arr[i+1]) flag=1;
            else {
                flag=0;
                break;
            }
            i++;
        }
        if (flag){
            while(i<n2-1){
            if (arr[i]>arr[i+1]) flag=1;
            else {
                flag=0;
                break;
            }
            i++;
            }
        }
    }
    return flag;

}
int Nam2(int arr[],int n2){
    int mtx=arr[0];
    int mti;
    if(checkDay_dinh_nui(arr,n2)==1){
    for (int i=0;i<n2;i++){
        if(mtx<arr[i]) {
            mtx=arr[i];
            mti=i;
        }
    }
   }
    else {
        mtx=-2;
        mti=-3;
    }
    return mtx+mti;
}
int Nam3(int arr1[],int n2){
    int max=arr1[0];
    int min=arr1[0];
    int maxi2;
    int mini2;
    for (int i=0;i<n2;i++){
        if (max<=arr1[i]) {
            max=arr1[i];
            maxi2=i;
        }
        if (min>=arr1[i]) {
            min=arr1[i];
            mini2=i;
        }
    }
    return maxi2+mini2;    

}
int Nam4(int arr1[],int n2){
    int max2_3x;
    int max2_3i;
    int posmax;
    int posmin;
    int max=arr1[0];
    int min=arr1[0];
    for (int i=0;i<3;i++){
        if (arr1[i]>=max) {
            max=arr1[i];
            posmax=i;
        }
        if (arr1[i]<=min) {
            min=arr1[i];
            posmin=i;
        }
    }
    if (max==min) {
        max2_3x=-5;
        max2_3i=-7;
    }
    else {
        for (int i=0;i<3;i++){
            if ((i!=posmax)&&(i!=posmin)) {
                max2_3i=i;
                max2_3x=arr1[i];
            }
        }
    }
    return max2_3x+max2_3i;
}
void docFile_Mustghost_su_kien13(string fileMust_ghost,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int & tiny,int & frog, int level_before){
    int n2;
    int arr[100];
    int arr1[100];
    char x;
    fstream input;
    input.open(fileMust_ghost,ios_base::in);
    input.seekg(0,ios::beg);
    input>>n2;
    for (int i=0;i<n2;i++){
        input>>arr[i];
        input>>x;
    }
    input.close();
    for(int i=0;i<n2;i++){
        arr1[i]=arr[i];
    }
    //biến đổi cho nấm 3 và nấm 4
    for(int i=0;i<n2;i++){
        if(arr1[i]<0) arr1[i]=-arr1[i];
        arr1[i]=(17*arr1[i]+9)%257;
    }
    int res1=Nam1(arr,n2);
    int res2=Nam2(arr,n2);
    int res3=Nam3(arr1,n2);
    int res4=Nam4(arr1,n2);
    int dec=1;
    int n=masukien[stt_su_kien];
    int chuso=checkchuso(n);
    chuso=chuso-2;
    for(int i=1;i<=(chuso);i++){
        dec*=10;
    }
    n=n%dec;
    if(Athur(maxHP)==0){
    for (int i=1;i<=chuso;i++){
        dec/=10;
        if(n/dec==1) {

            HP=HP-res1;
            }

        else if (n/dec==2) {
            HP=HP-res2;
            
        }
        else if (n/dec==3) {

            HP=HP-res3;
        }
        else {

            HP=HP-res4;
        }
        n=n%dec;
        healing(HP,level,maxHP,rescue,phoenixdown);
        
    }
    checkTiny(tiny,HP,maxHP,remedy);
    checkFrog(frog, level, level_before);
    }

    display(HP,level,remedy,maidenkiss,phoenixdown,rescue); 


} 
void sukien_15_17(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int & tiny,int & frog, int level_before)
{
    if ((remedy<99) && (masukien[stt_su_kien]==15)) remedy++;
    if ((maidenkiss<99) && (masukien[stt_su_kien]==16)) maidenkiss++;
    if ((phoenixdown<99) && (masukien[stt_su_kien]==17)) phoenixdown++;
    if (tiny>0)// Phải đặt vào trong từng hàm
        {
        tiny--;
        if (tiny==0) {
            HP=HP*5;
            if (HP>maxHP) HP=maxHP;
            }
        }  
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
}
void docFile_Asclepius(string fileAsclepius,int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int & gapAscle,int & tiny,int & frog, int level_before)
{
    int r1;//dòng 1
    int c1;//dòng 2
    // r1 dòng chứa c1 số nguyên dương cách nhau bỏi một dấu cách
    int so[100][100];
    
    fstream input;
    input.open(fileAsclepius,ios_base::in);
    input.seekg(0,ios::beg);
    input>>r1>>c1;
    for (int i=1;i<=r1;i++){
        for (int j=1;j<=c1;j++){
            input>>so[i][j];
        }
    }
    for (int i=1;i<=r1;i++){
        int j=1;
        int sothuoc_1dong=0;
        while (sothuoc_1dong<3 && j<=c1)
        {
            if (so[i][j]==16) {
                remedy++;
                if (remedy>99) remedy=99;
                sothuoc_1dong++;
                }
            else if (so[i][j]==17) {
                maidenkiss++;
                if (maidenkiss>99) maidenkiss=99;
                sothuoc_1dong++;
            }
            else if (so[i][j]==18) {
                phoenixdown++;
                if (phoenixdown>99) phoenixdown=99;
                sothuoc_1dong++;
            }
            j++;
        }
    }
    input.close();

    checkTiny(tiny,HP,maxHP,remedy);
    checkFrog(frog, level, level_before);   
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
}
void sukien_99(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP,int & tiny,int & frog, int level_before){
    if (Athur(maxHP)==1) {
        rescue=1;
        level=10;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
    else if(lancelot(maxHP)==1 && level>=8){
        rescue =1;
        level=10;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
    else if (level==10){
        rescue=1;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
    else {
        rescue=0;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
}



void phu_thuy_merlin(string filemerlin,int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int i,int masukien[] , int MaxHP, int &merlin,int & tiny,int maxHP, int & frog, int level_before)
{
    if (merlin == 0)
    {
        ifstream filein;
        filein.open(filemerlin, ios_base::in);
        int n9;
        filein >> n9;
        
        for (int i = 0; i < n9; i++)
        {
            string s;
            filein >> s;
            int cong = 1;
            if (s.length() >= 6)
            {
                for (int i = 0; i < s.length() - 5; i++)
                {
                    if (s.substr(i, 6) == "Merlin" || s.substr(i, 6) == "merlin")
                    {
                        
                        HP += 3;
                        cong--;
                        if (HP > MaxHP) HP = MaxHP;
                        break;
                    }
                }
                if (cong != 0)
                {
                    
                    string chuoi = "merlin";
                    int a[6];
                    for (int i = 0; i < 6; i++)
                    {
                        a[i] = chuoi[i];
                    }
                    
                   
                    bool kt=1;
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < s.length(); j++)
                        {
                            if (a[i] == s[j] || a[i] - 32 == s[j])
                            {
                                break;
                            }
                            if (j == s.length() - 1)
                            {
                                kt = 0;
                            }

                        }
                    }
                    if (kt == 1)
                    {
                        HP += 2;
                        if (HP > MaxHP)
                        {
                            HP = MaxHP;
                        }
                    }
                }
            }
        }

        filein.close();
    }
     merlin++;
    checkTiny(tiny,HP,maxHP,remedy);
    checkFrog(frog, level, level_before);
    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);     
}


void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    int masukien[20] ;
    string line1, line2;
    ifstream input;
    input.open(file_input,ios_base::in);
    int so_su_kien;
    int maxHP;
    rescue=-1;
    int tiny=0;
    int frog=0;
    int level_before;
    int gapAscle=0;
    int merlin=0;   
    bool Shanman;
    bool Siren; 
    string filemustghost, fileasclepius, filemerlin;
    while (input.eof() == false){
        getline(input, line1);
        stringstream ss(line1);
        ss>> HP >> level >> remedy >> maidenkiss >> phoenixdown;
        maxHP=HP;
        
        getline(input, line2);//Đọc dòng 2
      
                stringstream ss1(line2);
                masukien[0]={0};
                int i=1;
                while (ss1>>masukien[i]) {
                    i++;
                } 
        so_su_kien=i-1;

    
        //Đọc dòng 3
        
        getline(input,filemustghost,',');
        getline(input,fileasclepius,',');
        getline(input,filemerlin);

    }
    input.close();
    
    for (int i=1;i<=so_su_kien;i++){
            //Trong trạn thái tí hon và ếch thì sẽ không gặp lại sự kiện 6 và sự kiện 7 (đặt cuối cùng)
        if (i==so_su_kien) rescue=1;
        if ((lancelot(maxHP)==0) && (Athur(maxHP)==0)){
            
            if (((masukien[i]!=6) && (masukien[i]!=7))){  
                    if (masukien[i]==0) sukien_0(HP,level,remedy,maidenkiss,phoenixdown,rescue,tiny);
                    else if(1<=masukien[i] && masukien[i]<=5){
                        sukien_1_5(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                    }
                    else if (masukien[i]==11) MushMarrio(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                    else if (masukien[i]==12) Fibonaci(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                    else if ((15<=masukien[i])&&(masukien[i]<=17)) sukien_15_17(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                    else if (masukien[i]==19 && gapAscle==0) docFile_Asclepius(fileasclepius,HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,gapAscle,tiny,frog,level_before);
                    else if ((masukien[i]==18) && (merlin==0)) phu_thuy_merlin(filemerlin,HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,merlin,tiny,maxHP,frog,level_before);
                    else if (masukien[i]==99) sukien_99(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                    //Xep su kien 13 cuoi cung trong day
                    else {
                        docFile_Mustghost_su_kien13(filemustghost,HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                    }
                    if (rescue==0 || rescue==1) break;
            }
            else if (((masukien[i]==6)||masukien[i]==7)){
                if ((tiny==0)||(frog==0)){
                    if ((masukien[i]==7)  && (frog==0)){
                    //SirenVajsh (mã sự kiện 7)
                        level_before=level;
                        Siren=SirenVajsh(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                        if (Siren==0) frog=3;
                    }
                    else if (masukien[i]==6  && (tiny==0)){
                    //Shanman (mã sự kiện 6)
                        Shanman=Shaman(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
                        if (Shanman==0) tiny=3;
                    }

                }
                else if ((tiny>0)||(frog>0)){
                    if (tiny>0){
                        tiny--;
                        if (level<10) level+=2; 
                        if (level>10) level=10;
                        if (tiny==0) {
                            HP=HP*5;
                            if (HP>maxHP) HP=maxHP;
                        }
        
                    }
                    if (frog>0) {
                        if (level<10) level+=2; 
                        if (level>10) level=10;
                        frog--;
                        if (frog==0){
                            level=level_before;
                        }
                    
                    }
                        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);                       
                }
            
                if (rescue==0 || rescue==1) break;
            }
        }
        if ((lancelot(maxHP)==1) || (Athur(maxHP)==1)){
            if (masukien[i]>=1 && masukien[i]<=5) level++;
            else if (masukien[i]==6 || masukien[i]==7) level=level+2;
            else if (masukien[i]==99) sukien_99(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP,tiny,frog,level_before);
            if (level>10) level=10;
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            if (rescue==0 || rescue==1) break;
        }
        
    
    }
}