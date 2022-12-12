/*383179 Hüseyin Furkan MACAN*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <string>
#include<math.h>
#include<stdint.h>

using namespace std;


template <class T>
class Matrix{
    protected:
    int row;
    int col;
    int value;
    T **dynamicArray;

    public:
    void MatrixSet(T a,int b, int c);
    void resize(int inrow,int incol);
    void Print();
    void Print(string filename);
    Matrix<T> Tr();
    int det();
    Matrix();
    Matrix(T inrow,T incol,T value);
    Matrix<T> operator+(const T);
    Matrix<T> operator-(const T);
    Matrix<T> operator*(const T);
    Matrix<T> operator/(const T);
    Matrix<T> operator%(const T);
    Matrix<T> operator^(const T);
    Matrix<T> operator=(const Matrix<T>&);

    Matrix<T> operator+(const Matrix<T>&) const;
    Matrix<T> operator-(const Matrix<T>&) const;
    Matrix<T> operator*(const Matrix<T>&) const;

    Matrix<T> emul(const Matrix<T>&);
    Matrix<double> inv();
    virtual ~Matrix();
};


template<class T>
Matrix<T>::Matrix(){
    row=10;
    col=10;
    dynamicArray=new T*[row]; //satırlar için alan ayrılır.
    for(int i=0;i<row;i++){
    dynamicArray[i]=new T[col];
    }

    /*for(int j=0;j<row;j++){
        for(int k=0;k<col;k++){
            dynamicArray[j][k]=0;
        }
    }*/
}
template <class T>
Matrix<T>::Matrix(T inrow,T incol,T invalue){
    if(inrow>0 && incol>0){
        row=inrow;
        col=incol;
        value=invalue;
    }
    else{
        row=10;
        col=10;
    }
    dynamicArray=new T*[row]; //satırlar için alan ayrılır.
    for(int i=0;i<row;i++){
    dynamicArray[i]=new T[col];
    }
    if(value=='e'){
        if(col==row){
            for(int q=0;q<row;q++){

                    dynamicArray[q][q]=1;



            }
        }
    return;
    }
    if(value=='r'){
        for(int e=0;e<row;e++){
            for(int y=0;y<col;y++){
                dynamicArray[e][y]=rand()%256;
            }
        }
    return;
    }
    for(int j=0;j<row;j++){
        for(int k=0;k<col;k++){
            dynamicArray[j][k]=value;
        }
    }


}
template <class T>
void Matrix<T>::Print(){
    cout<<row<<"X"<<col<<endl;
    for(int j=0;j<row;j++){
        cout << "|";
        for(int k=0;k<col;k++){
            cout<<(T)dynamicArray[j][k]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------------"<<endl;
}

template <class T>
void Matrix<T>::Print(string filename){


  ofstream myfile
  (filename.c_str());

  if(myfile.fail()){
    cout<<"Dosya Açılamadı."<<endl;
  }
  else{
  for(int j=0;j<row;j++){
        myfile << "|";
        for(int k=0;k<col;k++){
            myfile<<dynamicArray[j][k]<<" ";
        }
        myfile<<"|"<<endl;
    }
    myfile<<"-------------------"<<endl;
    myfile.close();
}
}

template<class T>
void Matrix<T>::MatrixSet(T a, int b, int c){
this->dynamicArray[b][c]=a;
}
template <class T>
Matrix<T> Matrix<T>::Tr(){
    Matrix<T> *pivot=new Matrix<T>(col,row,0);
  /*  temp=new T*[col];
    for(int i=0;i<col;i++){
    temp[i]=new T[row];*/

for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        pivot->dynamicArray[j][i]=this->dynamicArray[i][j];
    }
}
/*dynamicArray=new T*[col];
    for(int i=0;i<col;i++){
    dynamicArray[i]=new T[row];
}
swap(row,col);
for(int x=0;x<row;x++){
    for(int y=0;y<col;y++){
        this->dynamicArray[x][y]=pivot->dynamicArray[x][y];
    }
}*/
/*for( int l = 0 ; l < row ; l++ )
delete [] temp[l] ;
delete [] temp ;*/
return (*pivot);
}

template <class T>
void Matrix<T>::resize(int inrow,int incol){
    if(incol>0 && inrow>0){
    T **temp;
        temp=new T*[inrow]; //satırlar için alan ayrılır.
    for(int i=0;i<inrow;i++){
    temp[i]=new T[incol];
}


    for(int v=0;v<inrow;v++){
        for(int b=0;b<incol;b++){
            if(value=='r'){
                temp[v][b]=rand()%256;
            }
            else if(value=='e'){
                temp[v][b]=0;
            }
            else{
                temp[v][b]=value;
            }
        }
    }

    if(row<inrow && col<incol){//3x3->5x5
        for(int a=0;a<row;a++){
            for(int b=0;b<col;b++){
                temp[a][b]=dynamicArray[a][b];
            }
        }
    }

    if(row<=inrow && col>incol){//3x3 ->2x4
        for(int c=0;c<inrow;c++){
            for(int d=0;d<col;d++){
                temp[c][d]=dynamicArray[c][d];
    }
}
}
    if(row>inrow && col<=incol){//3x3->4x2
        for(int e=0;e<row;e++){
            for(int f=0;f<incol;f++){
                temp[e][f]=dynamicArray[e][f];
    }
}
}
    if(row>=inrow && col>=incol){
        for(int g=0;g<inrow;g++){
            for(int h=0;h<incol;h++){
                temp[g][h]=dynamicArray[g][h];
    }
    }
    }
    row=inrow;
    col=incol;
    dynamicArray=new T*[row]; //satırlar için alan ayrılır.
    for(int i=0;i<row;i++){
    dynamicArray[i]=new T[col];
}

    for(int x=0;x<row;x++){
            for(int y=0;y<col;y++){
                dynamicArray[x][y]=temp[x][y];


}
}
/*if(value=='e'){
        if(incol==inrow){
            for(int q=0;q<incol;q++){

                    dynamicArray[q][q]=1;
                    }
                    }
        else{
            cout<<"Girilen değerler kare matris oluşturmamaktadır."<<endl;
            return;
        }
    }*/
    for( int l = 0 ; l < inrow ; l++ )
delete [] temp[l] ;
delete [] temp ;
}
}
template <class T>
Matrix<T>::~Matrix(){
for( int l = 0 ; l < row ; l++ )
delete [] dynamicArray[l] ;
delete [] dynamicArray ;
}

template<class T>
int Matrix<T>::det(){
    if(col!=row){
        cout<<"Girilen matris kare değil";
        return 0;
    }
    Matrix<T> *temp=new Matrix<T>(row-1,col-1,0);
    T determinant=0;
    T cof_i=0;
    T cof_j=0;
    if(row==1){
        return(this->dynamicArray[0][0]);
    }
    if(row==2){
        return((this->dynamicArray[0][0]*this->dynamicArray[1][1])-(this->dynamicArray[0][1]*this->dynamicArray[1][0]));
    }

        for(int k=0;k<col;k++){
            cof_i=0;
            for(int i=1;i<row;i++){
                cof_j=0;
                for(int j=0;j<col;j++){
                    if(j!=k){
                        temp->dynamicArray[cof_i][cof_j]=this->dynamicArray[i][j];
                        cof_j++;
                    }
                }
                cof_i++;
            }

        determinant=determinant + (pow(-1,k))*(this->dynamicArray[0][k])*(temp->det());
        }
    return determinant;


}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>&m) const{
    if(this->col==m.col && this->row==m.row){


    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp->dynamicArray[i][j]=(this->dynamicArray[i][j])+(m.dynamicArray[i][j]);
        }
    }
    return (*temp);
    }
    else{
    cout<<"Matris boyutları eşit değil!!"<<endl;
    return *this;
    }
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>&m) const{
    if(this->col==m.col && this->row==m.row){


    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp->dynamicArray[i][j]=(this->dynamicArray[i][j])-(m.dynamicArray[i][j]);
        }
    }
    return (*temp);
    }
    else{
    cout<<"Matris boyutları eşit değil!!"<<endl;
    return *this;
    }
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>&m) const{
if(this->col!=m.row){
    cout<<"Bu iki matris çarpılamaz";
    return (*this);
}
Matrix<T> *mul= new Matrix<T>(this->row,m.col,0);
for(int i=0;i<this->row;i++){
  for(int j=0;j<m.col;j++) {
    for(int k=0;k<this->col;k++){
        mul->dynamicArray[i][j]=this->dynamicArray[i][k]*m.dynamicArray[k][j];
    }
  }
}
return(*mul);
}

template<class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>&m){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=m.dynamicArray[i][j];
        }
    }
  return (*this);
}

template<class T>
Matrix<T> Matrix<T>::operator+(const T a) {
    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=(this->dynamicArray[i][j])+a;
        }
    }
 return  *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const T a) {
    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=(this->dynamicArray[i][j])-a;
        }
    }
 return  *this;
}
template<class T>
Matrix<T> Matrix<T>::operator*(const T a){
    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=(this->dynamicArray[i][j])*a;
        }
    }
 return  *this;
}

template<class T>
Matrix<T> Matrix<T>::operator/(const T a){
    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=(this->dynamicArray[i][j])/a;
        }
    }
 return  *this;
}

template<class T>
Matrix<T> Matrix<T>::operator%(const T a){
    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=(this->dynamicArray[i][j])%a;
        }
    }
 return  *this;
}

template<class T>
Matrix<T> Matrix<T>::operator^(const T a){
    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            this->dynamicArray[i][j]=pow((this->dynamicArray[i][j]),a);
        }
    }
 return  *this;
}

template<class T>
Matrix<T> Matrix<T>::emul(const Matrix<T>&m){
    if(this->col==m.col && this->row==m.row){


    Matrix<T> *temp = new Matrix<T>(row,col,0);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp->dynamicArray[i][j]=(this->dynamicArray[i][j])*(m.dynamicArray[i][j]);
        }
    }
    return (*temp);
    }
    else{
    cout<<"Matris boyutları eşit değil!!"<<endl;
    return *this;
    }
}
template <class T>
Matrix<double> Matrix<T>::inv(){
   Matrix<double> *Invtemp=new Matrix<double>(row,col,0);
    if(col!=row){
        cout<<"Girilen matris kare değil"<<endl;;
        //return (*this);
    }
    if(this->det()==0){
        cout<<"Bu matrisin tersi alınamaz"<<endl;
       // return (*this);
    }
    Matrix<T> *itemp=new Matrix<T>(row-1,col-1,0.0);
    Matrix<T> *cof=new Matrix<T>(row,col,0);
    Matrix<T> *cof2=new Matrix<T>(col,row,0);


    int cof_i=0;
    int cof_j=0;
    int count=-1;
        for(int q=0;q<row;q++){
            for(int k=0;k<col;k++){
            cof_i=0;
            for(int i=0;i<row;i++){
                cof_j=0;
                if(i==k){continue;}
                for(int j=0;j<col;j++){
                    if(j==k){continue;}
                        itemp->dynamicArray[cof_i][cof_j]=dynamicArray[i][j];

                        cof_j++;

                }
                cof_i++;
            }
            count++;


        cof->dynamicArray[q][k]=(pow(-1,count))*(itemp->det());

        }
        }
    double nD=(double)1/(this->det());
for(int u=0;u<row;u++){
    for(int l=0;l<col;l++){
        cof2->dynamicArray[l][u]=cof->dynamicArray[u][l];

    }
}
for(int g=0;g<row;g++){
    for(int f=0;f<col;f++){
        Invtemp->MatrixSet((cof2->dynamicArray[f][g])*nD, g, f );
        //Invtemp->dynamicArray[f][g]=(;
    }
}
    return (*Invtemp);

}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////TABLE CLASS////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <class T>
class Table : public Matrix<T>{
    private:
    string c[27]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string r[12]={"0","1","2","3","4","5","6","7","8","9","10"};
    //string *r;
    /*int row;
    int col;
    int value;
    T **dynamicArray;*/
    public:
    Table();
    Table(int r,int c,int d);
    Table(int r,int c,char ch);
    int itemAt(int r,int c);
    int itemAt(string rs,string cs);
    int itemAt(string s);
    void setRowNames(string s[],int n);
    ~Table();
    void Print();

};

template <class T>
Table<T>::Table(){
    this->row=10;
    this->col=10;
    /*this->dynamicArray=new T*[this->row]; //satırlar için alan ayrılır.
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }*/
    /*for(int i=0;i<1;i++){//to_string fonksiyonu bilgisayarımda çalışmadığından dinamik dizi kullanamadım.
        r[i] =to_string(i);
    }*/
    for(int j=0;j<this->row;j++){
        for(int k=0;k<this->col;k++){
            this->dynamicArray[j][k]=0;
        }
    }
}

template <class T>
Table<T>::Table(int r,int c,int d){
    if(r>0 && c>0){
        this->row=r;
        this->col=c;
        this->value=d;
       /* this->dynamicArray=new T*[this->row];
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }*/

    for(int j=0;j<this->row;j++){
        for(int k=0;k<this->col;k++){
            this->dynamicArray[j][k]=this->value;
        }
    }

    }
}
template <class T>
Table<T>::Table(int r,int c,char ch){
    if(r>0 && c>0){
        if(ch=='r'){

        this->row=r;
        this->col=c;

        this->dynamicArray=new T*[this->row];
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }

    for(int j=0;j<this->row;j++){
        for(int k=0;k<this->col;k++){
            this->dynamicArray[j][k]=rand()%256;
        }
    }


        }

    }
}

template<class T>
void Table<T>::Print(){
        cout<<"  ";
    for(int x=0;x<this->col;x++){
        cout<<c[x]<<" ";
    }
    cout<<endl;
    for(int j=0;j<this->row;j++){
        cout<<r[j]<< "|";
        for(int k=0;k<this->col;k++){
            cout<<this->dynamicArray[j][k]<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------------"<<endl;
}

template<class T>
int Table<T>::itemAt(int r,int c){
    if(r>0 && c>0){
        return this->dynamicArray[r][c];
    }
}

template<class T>
int Table<T>::itemAt(string rs,string cs){
    int x,y;
    for(int i=0;i<this->row;i++){
        if(r[i]==rs){
            x=i;
            }
            }
    for(int j=0;j<this->col;j++){
        if(c[j]==cs){
            y=j;
            }
}
return this->dynamicArray[x][y];
}

template<class T>
int Table<T>::itemAt(string s){
    int x,y;
    string z,t;
    z=s[1];
    t=s[0];
    for(int i=0;i<this->row;i++){
        if(r[i]==z){
            x=i;
            }
            }
    for(int j=0;j<this->col;j++){
        if(c[j]==t){
            y=j;
            }
}
return this->dynamicArray[x][y];
}

template<class T>
void Table<T>::setRowNames(string s[],int n){

    for(int i=0;i<n;i++){
        this->r[n]=s[n];
    }

}

template<class T>
Table<T>::~Table(){
    for( int l = 0 ; l < this->row ; l++ )
delete [] this->dynamicArray[l] ;
delete [] this->dynamicArray ;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////IMAGE CLASS////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//template<class T>
typedef struct rgb{
    int8_t r=0;
    int8_t g=0;
    int8_t b=0;
};


template <class T>
class Image: public Matrix<T>{
    protected:
    int16_t bftype;
    int32_t bfsize;
    int32_t reserved;
    int32_t bfoffset;
    int32_t bppixel;
    int32_t infosize;
    int16_t planes;
    int32_t compression;
    int32_t imagesize;
    int32_t xpix;
    int32_t ypix;
    int32_t ucolor;//color used
    int32_t impcolor;//color important
    int isbin=0;
    int t=1;
    int f=0;

    public:
    Image();
    Image(int width,int height);
    Image(string filename,string format);
    ~Image();
    void imread(string filename, string format);
    void dilation();
    void erosion();
    void opening();
    void closing();
    void gray2binary(int thr);
    void color2gray();
    void imwrite(string filename, string format);
    void iPrint();
    //void iPrint(string filename);
};

template <class T>
Image<T>::Image(){
    this->col=255;
    this->row=255;
    this->value=0;
    this->dynamicArray=new T*[this->row]; //satırlar için alan ayrılır.
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }
    for(int x=0;x<this->row;x++){
        for(int y=0;y<this->col;y++){
            this->dynamicArray[x][y].r=0;
            this->dynamicArray[x][y].g=0;
            this->dynamicArray[x][y].b=0;
        }
    }
}

template <class T>
Image<T>::Image(int width, int height){
    int check;
    if(height>0 && width>0){
    this->row=height;
    this->col=width;
    this->value=0;
    this->dynamicArray=new T*[this->row]; //satırlar için alan ayrılır.
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }
    for(int x=0;x<this->row;x++){
        for(int y=0;y<this->col;y++){
            this->dynamicArray[x][y].r=0;
            this->dynamicArray[x][y].g=0;
            this->dynamicArray[x][y].b=0;
        }
    }
    }
}

template<class T>
Image<T>::Image(string file,string format){
    if(format=="bin"){
this->isbin=1;
ifstream bin(file.c_str(),ios::in | ios::binary);
if(bin.fail()){
    cout<<"Dosya Açılamadı."<<endl;
  }
else {bin.read((char*)&(this->row),1);
cout<<this->row<<"x";
bin.read((char*)&(this->col),1);
cout<<this->col<<endl;

this->dynamicArray=new T*[this->row]; //satırlar için alan ayrılır.
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }

for(int x=0;x<this->row;x++){
    for(int y=0;y<this->col;y++){
        bin.read((char*)&this->dynamicArray[x][y].g,1);
       // bin.read((char*)&this->dynamicArray[x][y].g,1);
        //bin.read((char*)&this->dynamicArray[x][y].b,1);

        //bin.seekg(n,ios::beg);
        //n++;
    }
}
    bin.close();


}
}
    if(format=="bmp"){
        ifstream bmp(file.c_str(),ios::in | ios::binary);
          if(bmp.fail()){
            cout<<"Dosya Açılamadı.";
          }
          else{
          bmp.read((char*)&bftype,2);
int8_t red=0;
int8_t green=0;
int8_t blue=0;
  //bmp.seekg(2,ios::beg);
  bmp.read((char*)&bfsize,4);
  //seekg()
  bmp.read((char*)&reserved,4);

  //bmp.seekg(10,ios::beg);
  bmp.read((char*)&bfoffset,4);
  //bmp.seekg(14,ios::beg);
  bmp.read((char*)&infosize,4);
  //bmp.seekg(18,ios::beg);
  bmp.read((char*)&this->col,4);
  //bmp.seekg(22,ios::beg);
  bmp.read((char*)&this->row,4);
  //bmp.seekg(26,ios::beg);
  bmp.read((char*)&planes,2);
  //bmp.seekg(28,ios::beg);
  bmp.read((char*)&bppixel,2);
  bmp.read((char*)&compression,4);
  bmp.read((char*)&imagesize,4);
  bmp.read((char*)&xpix,4);
  bmp.read((char*)&ypix,4);
  bmp.read((char*)&ucolor,4);
  bmp.read((char*)&impcolor,4);

  int i=0,j=0;
  int8_t padding=4-(3*this->col)%4;
  if(padding==4) { padding=0; }
/*int8_t padding=(this->col*3+3)&(~3);*/

cout<<this->col<<endl<<this->row<<endl;


this->dynamicArray=new T*[this->row];
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }
bmp.seekg(54,ios::beg);
//bmp.seekg((int32_t)this->bfoffset,ios::beg);


for(i=0;i<this->row;i++) {
                    for(j=0;j< this->col;j++) {
  bmp.read((char*)&this->dynamicArray[i][j].r,1);
  bmp.read((char*)&this->dynamicArray[i][j].g,1);
  bmp.read((char*)&this->dynamicArray[i][j].b,1);
  swap(this->dynamicArray[i][j].r,this->dynamicArray[i][j].b);
  bmp.seekg(padding,ios::cur);

           };



                                   }


 /*int row_padded = (this->col*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    for(int i = 0; i < this->row; i++)
    {
        fread(data, imagesize(unsigned char), row_padded, bmp);
        for(int j = 0; j < this->col*3; j += 3)
        {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

            cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
        }
    }*/




  bmp.close();
}
}
}
template<class T>
void Image<T>::imread(string filename,string format){
    if(format=="bin"){
this->isbin=1;
ifstream bin(filename.c_str(),ios::in | ios::binary);
if(bin.fail()){
    cout<<"Dosya Açılamadı."<<endl;
  }
else {bin.read((char*)&(this->row),1);
cout<<this->row<<"x";
bin.read((char*)&(this->col),1);
cout<<this->col<<endl;

/*this->dynamicArray=new T*[this->row]; //satırlar için alan ayrılır.
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }*/

for(int x=0;x<this->row;x++){
    for(int y=0;y<this->col;y++){
        bin.read((char*)&this->dynamicArray[x][y].g,1);
       // bin.read((char*)&this->dynamicArray[x][y].g,1);
        //bin.read((char*)&this->dynamicArray[x][y].b,1);

        //bin.seekg(n,ios::beg);
        //n++;
    }
}
    bin.close();


}
}
    if(format=="bmp"){
        ifstream bmp(filename.c_str(),ios::in | ios::binary);
          if(bmp.fail()){
            cout<<"Dosya Açılamadı.";
          }
          else{
          bmp.read((char*)&bftype,2);
int8_t red=0;
int8_t green=0;
int8_t blue=0;
  //bmp.seekg(2,ios::beg);
  bmp.read((char*)&bfsize,4);
  //seekg()
  bmp.read((char*)&reserved,4);

  //bmp.seekg(10,ios::beg);
  bmp.read((char*)&bfoffset,4);
  //bmp.seekg(14,ios::beg);
  bmp.read((char*)&infosize,4);
  //bmp.seekg(18,ios::beg);
  bmp.read((char*)&this->col,4);
  //bmp.seekg(22,ios::beg);
  bmp.read((char*)&this->row,4);
  //bmp.seekg(26,ios::beg);
  bmp.read((char*)&planes,2);
  //bmp.seekg(28,ios::beg);
  bmp.read((char*)&bppixel,2);
  bmp.read((char*)&compression,4);
  bmp.read((char*)&imagesize,4);
  bmp.read((char*)&xpix,4);
  bmp.read((char*)&ypix,4);
  bmp.read((char*)&ucolor,4);
  bmp.read((char*)&impcolor,4);

  int i=0,j=0;
  int8_t padding=4-(3*this->col)%4;
  if(padding==4) { padding=0; }
/*int8_t padding=(this->col*3+3)&(~3);*/

cout<<this->col<<endl<<this->row<<endl;;


this->dynamicArray=new T*[this->row];
    for(int i=0;i<this->row;i++){
    this->dynamicArray[i]=new T[this->col];
    }
bmp.seekg(60,ios::beg);


for(i=0;i<this->row;i++) {
                    for(j=0;j< this->col;j++) {
  bmp.read((char*)&this->dynamicArray[i][j].r,1);
  bmp.read((char*)&this->dynamicArray[i][j].g,1);
  bmp.read((char*)&this->dynamicArray[i][j].b,1);
  swap(this->dynamicArray[i][j].r,this->dynamicArray[i][j].b);
  bmp.seekg(padding,ios::cur);

           };
                                   }

  bmp.close();
}
}
}

template<class T>
void Image<T>::color2gray(){
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->col;j++){
        int8_t temp;

            temp=(0.21*this->dynamicArray[i][j].r+0.72*this->dynamicArray[i][j].g+0.07*this->dynamicArray[i][j].b)/3;
            this->dynamicArray[i][j].g=temp;
            this->dynamicArray[i][j].r=temp;
            this->dynamicArray[i][j].b=temp;

            /*temp=(this->dynamicArray[i][j].r+this->dynamicArray[i][j].g+this->dynamicArray[i][j].b)/3;
            this->dynamicArray[i][j].g=temp;
            this->dynamicArray[i][j].r=temp;
            this->dynamicArray[i][j].b=temp;*/
        }
    }
}

template<class T>
void Image<T>::gray2binary(int thr){
    ofstream g2b("g2b.bin",ios::binary);

    if(g2b.fail()){
        cout<<"Dosya Oluşturulamadı."<<endl;
    }
    else{


    g2b.write((char*)&this->row,1);
    g2b.write((char*)&this->col,1);
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->col;j++){
            if(this->dynamicArray[i][j].g<thr){
                g2b.write((char*)&f,1);
            }
            if(this->dynamicArray[i][j].g>=thr){
                g2b.write((char*)&t,1);
            }
        }
    }
}
}

template <class T>
void Image<T>::dilation(){


    Image<rgb> *temp =new Image<rgb>(this->col,this->row);

    for(int q=0;q<this->row;q++){
    for(int w=0;w<this->col;w++){
    temp->dynamicArray[q][w].g=this->dynamicArray[q][w].g;
    }
}

    for(int i=1;i<this->row-1;i++){
        for(int j=1;j<this->col-1;j++){
//cout<<(int)(this->dynamicArray[i][j].r);
            for(int x=i-1;x<i+2;x++){
                for(int y=j-1;y<j+2;y++){
                    if(x==this->row && y==this->col){continue;}
                    if((int)this->dynamicArray[x][y].g==1){
                        temp->dynamicArray[i][j].g=1;

                    }
                }
            }
        }


    }

for(int q=0;q<this->row;q++){
    for(int w=0;w<this->col;w++){
      this->dynamicArray[q][w].g=temp->dynamicArray[q][w].g;
    }
}
cout<<endl;

cout<<"Dilation sonucunu görmek için tam ekran yapıp bir sayı girin"<<endl;
int c;
cin>>c;
    for(int n=0;n<this->row;n++){
            for(int m=0;m<this->col;m++){
                cout<<(int)this->dynamicArray[n][m].g;
            }
                cout<<endl;
            }


}

template<class T>
void Image<T>::erosion(){

    Image<rgb> *etemp =new Image<rgb>(this->col,this->row);

    for(int q=0;q<this->row;q++){
    for(int w=0;w<this->col;w++){
    etemp->dynamicArray[q][w].g=this->dynamicArray[q][w].g;
    }
}

    for(int i=1;i<this->row-1;i++){
        for(int j=1;j<this->col-1;j++){
            for(int x=i-1;x<i+2;x++){
                for(int y=j-1;y<j+2;y++){

                    if((int)this->dynamicArray[x][y].g==0){
                        etemp->dynamicArray[i][j].g=0;

                    }
                }
            }
        }


    }

for(int q=0;q<this->row;q++){
    for(int w=0;w<this->col;w++){
      this->dynamicArray[q][w].g=etemp->dynamicArray[q][w].g;
    }
}
cout<<endl;

cout<<"Erosion sonucunu görmek için tam ekran yapıp bir sayı girin."<<endl;
int l;
   cin>>l;
    for(int n=0;n<this->row;n++){
            for(int m=0;m<this->col;m++){
                cout<<(int)this->dynamicArray[n][m].g;
            }
                cout<<endl;
            }

    }

template<class T>
void Image<T>::opening(){
    if(isbin==1){
    cout<<"Opening işlemi yapılıyor (erosion+dilation)"<<endl;
    this->erosion();
    this->dilation();
    }
}

template<class T>
void Image<T>::closing(){
   if(isbin==1){
    cout<<"Closing işlemi yapılıyor (dilation +erosion)"<<endl;
    this->dilation();
    this->erosion();
    }
}

/*template<class T>
void Image<T>::color2gray(){
 int temp;

}*/

template<class T>
void Image<T>::imwrite(string filename,string format){
    int8_t red;
    int8_t green;
    int8_t blue;

    if(format=="bin"){
       ofstream out(filename.c_str(),ios::binary);
out.write((char*)&this->row,1);
//bin.seekg(1,ios::beg);
out.write((char*)&this->col,1);
//bin.seekg(2,ios::beg);

for(int x=0;x<this->row;x++){
    for(int y=0;y<this->col;y++){
        out.write((char*)&this->dynamicArray[x][y].g,1);

    }
}
    out.close();
    }
    if(format=="bmp"){

        ofstream obmp(filename.c_str(),ios::out | ios::binary);//çıktı
          obmp.write((char*)&bftype,2);
  obmp.seekp(2,ios::beg);
  obmp.write((char*)&bfsize,4);
  obmp.seekp(10,ios::beg);
  obmp.write((char*)&bfoffset,4);
  obmp.seekp(14,ios::beg);
  obmp.write((char*)&infosize,4);
  obmp.seekp(18,ios::beg);
  obmp.write((char*)&this->col,4);
  obmp.seekp(22,ios::beg);
  obmp.write((char*)&this->row,4);
  obmp.seekp(26,ios::beg);
  obmp.write((char*)&planes,2);
  obmp.seekp(28,ios::beg);
  obmp.write((char*)&bppixel,2);


  obmp.write((char*)&compression,4);
  obmp.write((char*)&imagesize,4);
  obmp.write((char*)&xpix,4);
  obmp.write((char*)&ypix,4);
  obmp.write((char*)&ucolor,4);
  obmp.write((char*)&impcolor,4);
  int o=0,p=0;
cout<<(int8_t)(this->bfoffset);
  int8_t padding=4-(3*this->col)%4;
  if(padding==4) { padding=0; }
    /*int8_t padding=(this->col*3+3)&(~3);*/

    obmp.seekp(54,ios::beg);
    //obmp.seekp((int8_t)this->bfoffset,ios::beg);
//cout<<(int32_t)this->bfoffset;


  for(int o=0;o<this->row;o++) {
                    for(p=0;p< this->col;p++) {
    swap(this->dynamicArray[o][p].r,this->dynamicArray[o][p].b);

  obmp.write((char*)&this->dynamicArray[o][p].r,1);
  obmp.write((char*)&this->dynamicArray[o][p].g,1);
  obmp.write((char*)&this->dynamicArray[o][p].b,1);           }
  obmp.seekp(padding,ios::cur);
                                   }
  obmp.close();









}
}
/*template <class T>
void Image<T>::iPrint(string filename){
    ofstream out(filename.c_str(),ios::binary);
int pivot;

for(int x=0;x<this->row;x++){
    for(int y=0;y<this->col;y++){
    pivot=(int)this->dynamicArray[x][y].g;
        out.write((char*)&pivot,1);

    }
}
    out.close();
}*/
template <class T>
Image<T>::~Image(){
for( int l = 0 ; l < this->row ; l++ )
delete [] this->dynamicArray[l] ;
delete [] this->dynamicArray ;
}
template<class T>
void Image<T>::iPrint(){

  int c;
  cout<<"Ekranı ayarlayıp bir sayı girin.";
  cin>>c;
  cout<<this->row<<"x"<<this->col<<endl;

  for(int i=0;i<this->row;i++){
    for(int j=0;j<this->col;j++){
        cout<<(int)this->dynamicArray[i][j].g;
    }
  cout<< endl;
  }

/*else{cout<<this->row<<"X"<<this->col<<endl;
    for(int j=0;j<this->row;j++){
        cout << "|";
        for(int k=0;k<this->col;k++){
            cout<<(int)this->dynamicArray[j][k].r<<(int)this->dynamicArray[j][k].g<<(int)this->dynamicArray[j][k].b<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"-------------------"<<endl;
}*/
}

int main()
{
Table<int> *m1=new Table<int>();
m1->Print();
//string st[3] = {"0. satır","1. satır","2. satır"};
//m1->Print();
//m1->setRowNames(st[3],3);
//m1->Print();
cout<<m1->itemAt("3","A")<<endl;
Matrix<int> *m2 =new Matrix<int>(4,4,4);
Matrix<int> *m5= new Matrix<int>(4,4,5);
m2->Print("a.txt");

m2->Print();
//m2->Tr().Print();
//((*m2)+(*m5)).Print();
((*m2)-3).Print();
//m2->inv().Print();
//cout<<m2->det()<<endl;
Matrix<int> *m3 =new Matrix<int>(3,3,3);
m3->Print();


//m3->Print();
//m3->Tr().Print();

//(m2)->emul(*m3).Print();

//((*m3)%(10)).Print();
//((*m3)^2).Print();

Image<rgb> *m4 =new Image<rgb>("image1.bin","bin");
//m4->iPrint();
//Image<rgb> *m4 =new Image<rgb>(,3);
//m4->iPrint("c.txt");
//m4->imwrite("imageout1.bmp","bmp");
//m4->color2gray();
m4->gray2binary(5);


m4->imread("g2b.bin","bin");
m4->iPrint();
m4->opening();
//Image<rgb> *m4 =new Image<rgb>(4,5);
//cout<<m4->dynamicArray[0][0].r;
//m4->iPrint();
//m4->iPrint();



//m4->iPrint();
m4->imwrite("imageout2.bmp","bmp");

    return 0;
}
