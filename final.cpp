#include<bits/stdc++.h>
using namespace std;


struct Node
{
       char e;
       Node* r;
       Node* l;
};
struct Node* newNode(char c)
{
       struct Node* Node = (struct Node*)malloc(sizeof(struct Node));

       Node->e=c;
       Node->l = NULL;
       Node->r = NULL;

       return(Node);
}
void insertion(Node* temp, char c)
{
   queue<Node*> t;
   t.push(temp);
   while (!t.empty()) {
        Node* temp = t.front();
        t.pop();
        if (!temp->l)
        {
             temp->l= newNode(c);
             break;
        }
        else
        t.push(temp->l);
        if(!temp->r)
        {
            temp->r=newNode(c);
            break;
        }
        else
        t.push(temp->r);
    }
}

void mirroring(struct Node* node)
{
    if (node==NULL)
       return;
    else
    {
        struct Node* temp;
        mirroring(node->l);
        mirroring(node->r);

        temp=node->l;
        node->l=node->r;
        node->r=temp;
    }
}

void inorder(struct Node *root) {
      if (root != NULL)
      {
         inorder(root->l);
         cout<<root->e;
         inorder(root->r);
       }
}

string printingLevelOrder(Node *root)
{
      string p= "";

       if (root == NULL)
          return "";
       queue<Node *> t;
       t.push(root);
       while (t.empty() == false)
       {
          Node *node = t.front();
          char c= node->e;
         //cout << c;
         p += c;
         t.pop();
         if (node->l != NULL)
            t.push(node->l);
         if (node->r != NULL)
            t.push(node->r);
       }
       return p;
}

string decryption(string s) {

        Node* root=newNode(s[0]);
        int i;
        for(i=1;i<s.length();i++)
        {
           insertion(root,s[i]);
        }

        mirroring(root);
        string x = printingLevelOrder(root);
        //cout << "reversed mirrored string : " << x;
        string decrypted = "";
        for(i=0;i<x.length();i++)
        {
           int position = i + 1;
           int ascii = x[i];
           if (position%2 == 0) {
              ascii = ascii - i;
           }
           else {
              ascii = ascii - i - 2;
           }
           //cout << ascii << " ";
           decrypted += ascii;
        }
        return decrypted;

}

main()
{
      string str;
      cout << "Enter the String you want to encrypt" << "\n";
      getline(cin,str);
      int arr[str.length()],i;

      for(i=0;i<str.length();i++)
      {
          int ascii;
          ascii=str[i];
          arr[i]=ascii;
      }
      cout<<"\n";

      for(i=0;i<str.length();i+=2)
      {
          arr[i]+=i+2;
          arr[i+1]+=i+1;
      }

      string s;
      for(i=0;i<str.length();i++)
      {
         s+=char(arr[i]);
      }

      Node* root=newNode(s[0]);

      for(i=1;i<str.length();i++)
      {
         insertion(root,s[i]);
      }
      cout << "Original String given : " << str << "\n";
      mirroring(root);
      string p = printingLevelOrder(root);
      cout << "Encrypted String is : " << p << "\n";
      string decrypted = decryption(p);
      cout << "Decrypted String : " << decrypted << "\n";
      return 0;
}
