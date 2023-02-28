#include "knight.h"


void sukien_0(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue){
        rescue=1;
    }
void giaotranh(int & HP, int & level, int damage, int levelO, int maxHP, int & rescue , int & phoenixdown ){
    if (level>levelO) {
        if(level<10) level++;
        }
    else if (level<levelO) {
        HP=HP-damage;
        if (HP <= 0 && phoenixdown>0) {
            HP=maxHP;
            phoenixdown--;
        }
        else if (HP<=0 && phoenixdown==0) rescue=0;
        
    }

}
void sukien_1_5(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP){
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
    
    giaotranh(HP,level,damage,levelO,maxHP,rescue,phoenixdown);


}
int Shaman(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP){
    int b = stt_su_kien%10;
    int levelO= stt_su_kien > 6?(b > 5?b : 5) : b;
    if (level>levelO){
        if (level<10) level+=2;
        if (level>10) level=10;
    }
    else if(level<levelO){
        //trạng thái tí hon
        if (remedy==0) {
        if(HP<5) HP=1;
        else HP=HP/5;
        }
        else remedy--;
    }
    return 3;
     // 3 sự kiện tiếp theo vẫn ở trạng thái tí hon, đến sự kiện thứ tư thì HP=HP*5;
}
int SirenVajsh(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP){
    int b = stt_su_kien%10;
    int levelO= stt_su_kien > 6?(b > 5?b : 5) : b;
    if (level>levelO){
        if (level<10) level+=2;
        if (level>10) level=10;
    }
    else if(level<levelO){
        //biến thành ếch
        if (maidenkiss==0) 
        level=1;
        else maidenkiss--;
    }
    return 3; // 3 sự kiện tiếp theo vẫn ở trạng thái tiếp theo, đến sự kiện thứ tư thì level trở lại trước lúc biến thành ếch; tạo biến level lúc biến thành ếch để lưu lại ở đoạn main
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
void MushMarrio(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP){
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
}

void Fibonaci(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue,int stt_su_kien,int masukien[],int maxHP){
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
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}


void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    cout << "Function isn't implemented" << endl;
    int masukien[20] ;
    string line1, line2;
    ifstream input;
    input.open(file_input,ios_base::in);
    int so_su_kien;
    int maxHP;
    rescue=-1;
    int temp=0;
    while (input.eof() == false){
        getline(input, line1);
        stringstream ss(line1);
        
        ss>> HP >> level >> remedy >> maidenkiss >> phoenixdown;
        cout << HP << level << remedy << maidenkiss << phoenixdown<<endl;
        maxHP=HP;
        
        getline(input, line2);//Đọc dòng 2
      
                stringstream ss1(line2);
                masukien[0]={0};
                int i=1;
                while (ss1>>masukien[i]) {
                    
                    cout << masukien[i]<<" ";
                    i++;
                } 
        so_su_kien=i-1;

    
        //Đọc dòng 3
        string filemustghost, fileasclepius, filemerlin;
        getline(input,filemustghost,',');
        getline(input,fileasclepius,',');
        getline(input,filemerlin);

    }
    input.close();
    
    for (int i=1;i<=so_su_kien;i++){
        //Trong trạn thái tí hon và ếch thì sẽ không gặp lại sự kiện 6 và sự kiện 7 (đặt cuối cùng)
        if (((masukien[i]!=6) && (masukien[i]!=7))){  
                if(1<=masukien[i] && masukien[i]<=5){
                    sukien_1_5(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP);
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                }
                else if (masukien[i]==11) MushMarrio(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP);
                else if (masukien[i]==12) Fibonaci(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP);

                if (temp>0)
                {
                    temp--;
                    if (temp==0) {
                        HP=HP*5;
                        if (HP>maxHP) HP=maxHP;
                    }
                }
        }
        else if (((masukien[i]==6)||masukien[i]==7)){
            if (temp==0){
                if (masukien[i]==7){
                //SirenVajsh
                    temp=SirenVajsh(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP);
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                }
                if (masukien[i]==6){
                //Shanman
                    temp=Shaman(HP,level,remedy,maidenkiss,phoenixdown,rescue,i,masukien,maxHP);
                    display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                }
            }
            else if (temp>0){
                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                temp--;
                if (temp==0) {
                    HP=HP*5;
                    if (HP>maxHP) HP=maxHP;
                }               
            }
        }
        
      if (i==so_su_kien) {
            rescue=1;
            exit(0);
        }
        if (HP==0){
            rescue=-1;
            exit(0);
        }
    
}
}