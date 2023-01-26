
#include<iostream>
using namespace std;

struct node {
                     int price;
                     string author, title;
                     node *next_add;
             };
class book{
public:
         int size= 0;
         node *head = NULL; 
         void showmenu(void);
         void menu(int);
         void insert_book(node**, int);
         void search_book(void);
         void update_book(void);
         void delete_book(node**, int); 
         void display_book(void);
};  
void book::showmenu(){
    int choice;
    do{
        
       menu(choice);
       
    }while(choice<6);
    
}
void book::menu(int choice){
                 
                 cout<<"1. Insert new book"<<endl;
                 cout<<"2. Delete a book"<<endl;
                 cout<<"3. Update book details"<<endl;
                 cout<<"4. Search a book"<<endl;
                 cout<<"5. Display all books"<<endl;
                 cout<<"6. Exit"<<endl;
                 cout<<"Please enter your choice"<<endl;
                 cin>>choice;
              
                 switch(choice)
                 {
                               case 1:
                                    int ipos;
                                    cout<<"At which position you wish to place the book (position starts from 0): "<<endl;
                                    cin>>ipos;
                                    insert_book(&head, ipos);
                                    break;
                               case 2:
                                    int dpos;
                                    cout<<"Enter the position you want to delete the book from (position starts from 0): " <<endl;
                                    cin>>dpos;
                                    delete_book(&head, dpos);
                                    break;
                               case 3:
                                    
                                    update_book();
                                    break;
                               case 4:
                                    
                                    search_book();
                                    break;
                               case 5:
                                    
                                    display_book();
                                    break;
                               case 6:
                                    break;
                               default:
                                    cout<<"Invalid choice"<<endl;
                                    }
            } 
            
void book:: insert_book(node** head, int pos){
               
               node  *new_node = new node;
               cout<<endl;
               cout<<"Book title: "<<endl;
               cin>>new_node->title;
               cout<<"Book author: "<<endl;
               cin>>new_node->author;
               cout<<"Book price: "<<endl;
               cin>>new_node->price;
               new_node->next_add = NULL;
              if(pos < 0 || pos > size) 
                      cout<<"Invalid position"<<endl;
              else if(pos == 0){
                     new_node->next_add = *head; 
                     *head = new_node;
                      size++;
                }     
              else{
                   node* temp = *head; 
                   while(--pos > 0){
                   temp = temp->next_add;
                   }
              new_node->next_add= temp->next_add;
              temp->next_add = new_node;
              size++;
    }  
              
}  

void book::search_book(){
           string searchbook;
           int found=0;
           if (head == NULL)
           cout<<"There is no book"<<endl;
           else{
              cout<<"Enter the title of the book: "<<endl;
              cin>>searchbook;
              struct node *ptr= head;
              while(ptr != NULL)
              {
                        if(ptr->title == searchbook)
                        {
                                      cout<<endl;
                                      cout<<"Book found"<<endl;
                                      cout<<"Book title: "<<ptr->title<<endl;
                                      cout<<"Book author: "<<ptr->author<<endl;
                                      cout<<"Book price: "<<ptr->price<<endl;
                                      found=1;
                        }              
                    ptr = ptr->next_add;
               
                }
           }
                if(found==0)
                cout<<"Book not found"<<endl;
                
      
      }
      
void book::update_book(){
           string searchbook;
           int found=0;
           if (head == NULL)
           cout<<"There is no book"<<endl;
           else{
              cout<<"Enter the title of the book: "<<endl;
              cin>>searchbook;
              
              node *ptr = head;
              while(ptr != NULL)
              {
                        if(searchbook == ptr->title)
                        {
                                      cout<<"Book found"<<endl;
                                      cout<<"Update book title: "<<endl;
                                      cin>>ptr->title;
                                      cout<<"Update book author: "<<endl;
                                      cin>>ptr->author;
                                      cout<<"Update book price: "<<endl;
                                      cin>>ptr->price;
                                      found=1;
                                      cout<<"Book details have been updated"<<endl;
                        }              
                    ptr = ptr->next_add;
               
                }
                if(found==0)
                cout<<"Book not found"<<endl;
           }
 }    
 
void book::delete_book(node** head, int pos){
            if (*head == NULL){
            cout<<"Linked list is already empty"<<endl;
            return;
            }
            node* temp = *head;
            if (pos == 0){
            *head = temp->next_add;
             
             return;
            }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next_add;
 
    if (temp == NULL || temp->next_add == NULL)
        return;
 
    node* next_add = temp->next_add->next_add;
     
    temp->next_add = next_add;
}
 
void book::display_book(){
      node* temp=head;
      while(temp!=NULL){
                        cout<<"Book title: "<<temp->title<<endl;
                        cout<<"Book author: "<<temp->author<<endl;
                        cout<<"Book price: "<<temp->price<<endl;
                        temp=temp->next_add;
                        }
              cout<<endl;
      }                   
           
int main()
   {
       int choice;
       book b;
       b.showmenu();
       return 0;                                          
}                                 
           
   

