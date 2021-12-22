#include <bits/stdc++.h>

using namespace std;

struct node{
    bool is_regular;
    int data,depth;
    node *parent,*left,*right;
    
    node(node *p){
        depth=-1;
        is_regular=false;
        parent=p;
        left=right=nullptr;
    }
};

struct cmp{
    bool operator()(node *n1,node *n2){
        if(n1->depth==n2->depth){
            while(n1->parent!=n2->parent){
                n1=n1->parent; 
                n2=n2->parent;
            }
            return n1==n2->parent->right;
        }
        if(n1->depth>n2->depth){
            while(n1->depth-1>n2->depth) n1=n1->parent;
            while(n1->parent!=n2){
                n1=n1->parent;
                n2=n2->parent;
            }
            return n1==n2->right;
        }
        if(n1->depth<n2->depth){
            while(n2->depth-1>n1->depth) n2=n2->parent;
            while(n2->parent!=n1){
                n1=n1->parent;
                n2=n2->parent;
            }
            return n2==n1->left;
        }
        return false;
    }
};

struct tree{
    node *root=new node(nullptr);
    queue<node*> to_explode;
    priority_queue<node*,vector<node*>,cmp> to_split;

    void read(string &str){
        node *now=root;
        for(auto ch:str){
            switch(ch){
                case '[':{
                    node *child=new node(now);
                    child->depth=now->depth+1;
                    now->left=child;
                    now=child;
                    break;
                }
                case ']':{
                    now=now->parent;
                    break;
                }
                case ',':{
                    now=now->parent;
                    node *child=new node(now);
                    child->depth=now->depth+1;
                    now->right=child;
                    now=child;
                    break;
                }
                default:{
                    now->is_regular=true;
                    now->data=ch-'0';
                    break;
                }
            }
        }
    }

    tree(){
        root->depth=0;
    }

    void check_explode(node *now){
        //cout<<now<<' '<<now->is_regular<<' '<<now->data<<' '<<now->depth<<endl;
        if(!now->is_regular){
            check_explode(now->left);
            if(now->depth>=4&&now->left->is_regular&&now->right->is_regular) to_explode.push(now);
            check_explode(now->right);
        }
    }

    void explode_one(node *now){
        node *temp=now->parent,*now_temp=now;
        //cout<<now<<' '<<'['<<now->left->data<<','<<now->right->data<<']'<<endl;
        
        while(temp!=nullptr){ //왼쪽으로 가는 경로가 있을때까지 부모로 올라감
            if(temp->left!=now_temp&&temp->left!=nullptr){
                temp=temp->left;
                while(!temp->is_regular){ //왼쪽에 있는 서브트리에서 가장 오른쪽에 더해줌
                    temp=temp->right;
                }
                //cout<<temp->data<<"+="<<now->left->data<<endl;
                temp->data+=now->left->data;
                if(temp->data>9&&temp->data-now->left->data<=9) to_split.push(temp);
                break;
            }
            now_temp=temp;
            temp=temp->parent;
        }
        temp=now->parent,now_temp=now;
        while(temp!=nullptr){ //오른쪽으로 가는 경로가 있을때까지 부모로 올라감
            if(temp->right!=now_temp&&temp->right!=nullptr){
                temp=temp->right;
                while(!temp->is_regular){ //오른쪽에 있는 서브트리에서 가장 완쪽에 더해줌
                    temp=temp->left;
                }
                //cout<<temp->data<<"+="<<now->right->data<<endl;
                temp->data+=now->right->data;
                if(temp->data>9&&temp->data-now->right->data<=9) to_split.push(temp);
                break;
            }
            now_temp=temp;
            temp=temp->parent;
        }
        //delete now->left;
        //delete now->right;
        now->is_regular=true;
        now->data=0;
        now->left=now->right=nullptr;
    }

    int explode(void){ //Depth>=4, left,right is regular   explode 된 노드 개수 return
        check_explode(root);

        int cnt=to_explode.size();
        while(to_explode.size()){
            node *now=to_explode.front();
            to_explode.pop();
            explode_one(now);
            //cout<<"check"<<endl;
        }
        return cnt;
    }


    void split_one(node *now){
        node *left=new node(now);
        node *right=new node(now);
        left->depth=right->depth=now->depth+1;
        left->data=now->data/2; right->data=now->data-now->data/2;
        left->is_regular=right->is_regular=true;
        now->is_regular=false;
        now->left=left;
        now->right=right;
        if(now->left->data>9) to_split.push(left);
        if(now->right->data>9) to_split.push(right);
        if(now->depth>=4) explode_one(now);
    }

    void split(void){
        while(to_split.size()){
            node *now=to_split.top();
            //cout<<now<<' '<<now->data<<endl;
            to_split.pop();
            if(now->parent->left==now||now->parent->right==now) split_one(now);
        }
    }

    void add(tree *op){
        node *new_root=new node(nullptr);
        root->parent=new_root;
        op->root->parent=new_root;
        new_root->left=root;
        new_root->right=op->root;
        root=new_root;
        stack<node*> s;
        map<node*,bool> visited;
        s.push(root);
        while(s.size()){
            node *now=s.top();
            if(now==nullptr||visited[now]){
                s.pop();
                continue;
            }
            visited[now]=true;
            now->depth++;
            s.push(now->left);
            s.push(now->right);
        }
    }

    int magnitude(node *now){
        //cout<<now<<' '<<now->is_regular<<' '<<now->depth<<endl;
        if(now->is_regular) return now->data;
        return 3*magnitude(now->left)+2*magnitude(now->right);
    }

    void print(void){
        node *now=root;
        stack<node*> s;
        map<node*,bool> visited;
        s.push(root);
        while(s.size()){
            node *now=s.top();
            if(now==nullptr){
                s.pop();
                continue;
            }
            if(visited[now]){
                cout<<']';
                s.pop();
                continue;
            }
            visited[now]=true;
            cout<<'[';
            if(now->is_regular) cout<<now->data;
            s.push(now->right);
            s.push(now->left);
        }
    }
    node *copy(node *now,node *parent){
        if(now==nullptr) return nullptr;
        node *ret=new node(nullptr);
        *ret=*now;
        ret->left=copy(now->left,ret);
        ret->right=copy(now->right,ret);
        ret->parent=parent;
        return ret;
    }
};

vector<tree*> trees;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        tree *now=new tree;
        trees.push_back(now);
        now->read(temp);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            tree *left=new tree,*right=new tree;
            left->root=trees[i]->copy(trees[i]->root,nullptr);
            right->root=trees[j]->copy(trees[j]->root,nullptr);
            left->add(right);
            left->explode();
            left->split();
            int temp=left->magnitude(left->root);
            //cout<<temp<<endl;
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;

}