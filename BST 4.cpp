#include<iostream> 
using namespace std; 
 
class bstnode 
{ 
 public : 
  int data ; 
  bstnode *left,*right; 
  bstnode(int x) 
  { 
   data=x; 
   left=right=NULL; 
    
  }  
}; 
 
class bst 
{ 
 bstnode*root; 
 public: 
  bst() 
  { 
   root=NULL; 
    
  } 
   
  bstnode* create(); 
  void insert (int x); 
  bstnode* find(int x); 
  bstnode* find_min(bstnode*node); 
  bstnode* find_max(bstnode*node); 
  int longest_path(bstnode*node); 
  void display(bstnode*node); 
  bstnode*mirror(bstnode*node); 
   
  bstnode*get_root() 
  { 
   return root; 
    
  } 
     
}; 
 
bstnode*bst::create() 
 
{ 
 int x,i,n; 
 cout<<"Enter the total number of nodes ="; 
 cin>>n; 
  
 cout<<"Enter the values ="; 
 for(i=0;i<n;i++) 
 { 
  cin>>x; 
  insert(x); 
   
 } 
 return root; 
} 
 
void bst::insert(int x) 
{ 
 bstnode*newNode=new bstnode(x); 
 if(root==NULL) 
 { 
  root=newNode; 
  return; 
   
 } 
 bstnode*p=root; 
 bstnode*q=NULL; 
  
 while(p!=NULL) 
 { 
  q=p; 
  if(x>p->data) 
  { 
   p=p->right; 
    
  } 
  else 
  { 
   p=p->left; 
        } 
 } 
  
  
  if(x>q->data) 
  { 
   q->right=newNode; 
    
  } 
  else 
  { 
   q->left=newNode; 
    
  } 
   
  
} 
 
bstnode*bst::find(int x) 
{ 
 bstnode*p=root; 
 while(p!=NULL) 
 { 
  if(x==p->data) 
  { 
   return p; 
  } 
  if(x>p->data) 
  { 
   p=p->right; 
  } 
  else 
  { 
   p=p->left; 
  } 
    } 
 return NULL; 
   
} 
 
bstnode*bst::find_min(bstnode*node) 
{ 
 while(node&&node->left!=NULL) 
 { 
  node=node->left; 
 } 
 return node; 
  
} 
 
bstnode*bst::find_max(bstnode*node) 
{ 
 while(node&&node->right!=NULL) 
 { 
  node=node->right; 
 } 
 return node; 
  
} 
int bst::longest_path(bstnode*node) 
{ 
  if(node!=NULL) 
  { 
   return 0; 
  } 
  int leftHight=longest_path(node->left); 
  int rightHight=longest_path(node->right); 
  return max(leftHight,rightHight) +1; 
    
} 
 
void bst::display(bstnode*node) 
{ 
 if(node!=NULL) 
 { 
  display(node->left); 
  cout<<"\t"<<node->data; 
  display(node->right); 
 } 
} 
 
bstnode*bst::mirror(bstnode*node) 
{ 
 if(node==NULL) 
 { 
  return NULL; 
 } 
 bstnode*temp=node->left; 
 node->left=mirror(node->right); 
 node->right=mirror(temp); 
 return node ; 
} 
 
int main() 
{   int ch,x; 
 bst b; 
 bstnode*p,*root=NULL; 
  
 do 
 { 
  cout<<"\n1. CREATE \n2. FIND \n3. FIND MIN \n4. FIND MAX"; 
  cout<<"\n5.LONGEST PATH \n6. DISPLAY \n7. MIRROR \n8.EXIT"; 
  cout<<"Enter your choice ="; 
  cin>>ch; 
   
  switch(ch) 
  { 
   case 1: 
    root=b.create(); 
    break; 
     
         case 2: 
          cout<<"Enter node to be search ="; 
          cin>>x; 
          p=b.find(x); 
          if(p==NULL) 
          { 
           cout<<"Node not found "; 
            
    } 
    else 
    { 
     cout<<"Node found "<<p->data; 
      
    } 
    break; 
     
   case 3: 
    p=b.find_min(b.get_root()); 
    if(p) 
    { 
     cout<<"Minimum value in tree"<<p->data; 
    } 
    else 
    { 
     cout<<"Tree is empty "; 
      
    } 
    break; 
     
   case 4: 
    p=b.find_max(b.get_root()); 
    if(p) 
    { 
     cout<<"Maximum value in tree"<<p->data; 
    } 
    else 
    { 
     cout<<"Tree is empty "; 
      
    } 
    break; 
     
      case 5: 
       cout<<"Longest path in tree is ="; 
       cout<<b.longest_path(b.get_root()); 
       break; 
        
      case 6: 
       b.display(b.get_root()); 
       break; 
        
      case 7: 
       root=b.mirror(b.get_root()); 
cout<<"Tree Mirror"; 
break; 
} 
}while(ch!=8); 
return 0; 
} 

