#include <iostream>
using namespace std;

//Trong siêu thị người ta xếp hàng để thực hiện thanh toán. Mỗi giỏ hàng với các hàng hoá được coi như một node trong một cấu trúc hàng đợi.  
//Khai báo cấu trúc hàng đợi. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
struct Product{
    string name;    //ten san pham
    float cash;    //so tien cua san pham
};
struct CustomerNode{
    int id; //ma gio hang
    string name;    //tenn khach hang
    Product sanpham[20];    //cac sanpham co trong gio hang
    int sosp;      //tong so luong san pham co trong gio hang
    double price;    //tong so tien phai thanh toan
    CustomerNode *next; //con tro toi gio hang tiep theo

};
//khoi tao hang doi
struct Queue{
    CustomerNode *front;    //con tro dau hang doi
    CustomerNode *rear;     //con tro cuoi hang doi

};
void initQueue(Queue *q){
    q->front=nullptr;
    q->rear=nullptr;
}
//ham ktra rong
int isempty(Queue *q){
    return q->front==nullptr&&q->rear==nullptr;
}
//nhap thong tin gio hang
CustomerNode* inputcustomer(){
    CustomerNode *p = new CustomerNode();
    p->next=nullptr;
    cout <<"ma gio hang: "; cin>>p->id;
    //nhap ten khach hang
    cin.ignore();   //xoa bo nho dem trc khi nhap
    cout<<"nhap ten: ";
    getline(cin, p->name);
    cout<<"nhap so luong sp: "; cin>>p->sosp;
    p->price = 0;
    for(int i=0;i<p->sosp;i++){
        cin.ignore();
        cout<<"ten sp thu "<<i+1;
        getline(cin,p->sanpham[i].name);
        cout << "gia: "; cin>>p->sanpham[i].cash;
        p->price+=p->sanpham[i].cash;
    }
    return p;
}
//them vao hang doi
void enqueue( Queue *q, CustomerNode *customer ){
    if(isempty) q->front=q->rear=customer;
    q->rear->next=customer;
    q->rear = customer;
    q->rear->next=nullptr;  //dam bao node cuoi tro ve null
}
//Loại bỏ từng người ra khỏi hàng đợi sau khi người đó đã thực hiện thanh toán xong 
void dequeue(Queue *p){
    if(isempty) return;   
    CustomerNode *del = p->front;
    p->front=del->next;
    delete del;
    if(p->front==nullptr)   p->rear=nullptr;    //ktra neu queue co 1ptu thi reset f,n

}
//Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên làm việc  
double revenue(Queue *q){       //su dung ham nay cuoi cung
    double total=0;
    if(isempty) return 0;
    CustomerNode *p=q->front;
    while(q->front){
        total += p->price;
        dequeue(q);        
    }
    return total;
}
//Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân  
int countsp(Queue *q, string A){
    int slg=0;
    if (isempty) return slg;
    CustomerNode *p=q->front; //tao con tro duyet p
    while(p){

        for(int i=0;i<p->sosp;i++){
            if(p->sanpham[i].name==A){
                slg++;
            }
        }
    p=p->next;
    }
    return slg;

}