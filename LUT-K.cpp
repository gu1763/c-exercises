#include<stdio.h>
#include<stdlib.h>
struct node{
    int v;
    int c;
    struct node *next;
};
int main()
{
    int k,n,m;
    scanf("%d %d %d",&k,&n,&m);
    struct node *haq_h=NULL,*haq_t=NULL;
    struct node *cq_h=NULL,*cq_t=NULL;
    int haq_len=0;
    int cq_len=0;
    
    for(int i=0;i<m;i++)
    {
        int data;
        scanf("%d",&data);
        int f=0,fff=0;

        struct node* p=cq_h;
        if(p&&p->v==data) 
		{
            if(p!=cq_t) { 
                cq_h=p->next;
                p->next=NULL;
                cq_t->next=p;
                cq_t=p;
            }
            continue;
        }
        while(p&&p->next) 
		{
            if(p->next->v==data) {
                fff=1;
                struct node* temp=p->next;
                p->next=temp->next;
                if(temp==cq_t) cq_t=p;
                temp->next=NULL;
                cq_t->next=temp;
                cq_t=temp;
                break;
            }
            p=p->next;
        }
        if(fff) continue;


        if(haq_h&&haq_h->v==data) {
            f=1;
            haq_h->c++;
            if(haq_h->c==k) {
                struct node* o=(struct node*)malloc(sizeof(struct node));
                o->v=data; o->c=1; o->next=NULL;
                if(cq_t) {cq_t->next=o; cq_t=o;} 
                else cq_h=cq_t = o;
                cq_len++;
                
                struct node* del=haq_h;
                haq_h=haq_h->next;
                if(!haq_h) haq_t=NULL;
                free(del);
                haq_len--;
                
            } else { 
                if(haq_h !=haq_t) {
                    struct node* temp=haq_h;
                    haq_h=haq_h->next;
                    temp->next=NULL;
                    haq_t->next=temp;
                    haq_t=temp;
                }
            }
        }


        if(f==0&& haq_h) {
            struct node* cur=haq_h;
            while(cur->next) {
                if(cur->next->v == data) {
                    f=1;
                    cur->next->c++;
                    if(cur->next->c == k) {
                        struct node* a = (struct node*)malloc(sizeof(struct node));
                        a->v=data; a->c=1; a->next=NULL;
                        if(cq_t) { cq_t->next = a; cq_t=a; }
                        else cq_h=cq_t=a;
                        cq_len++;
                        
                        struct node* del=cur->next;
                        cur->next=del->next;
                        if(del==haq_t) haq_t=cur;
                        free(del);
                        haq_len--;
                    } else {
                        struct node* temp=cur->next;
                        cur->next=temp->next;
                        if(temp==haq_t) haq_t=cur;
                        temp->next=NULL;
                        haq_t->next=temp;
                        haq_t=temp;
                    }
                    break;
                }
                cur=cur->next;
            }
        	}


        if(f==0) {
            struct node* a=(struct node*)malloc(sizeof(struct node));
            a->v=data; a->c=1; a->next=NULL;
            if(haq_t) { haq_t->next=a; haq_t=a; }
            else haq_h=haq_t=a;
            haq_len++;
            if(haq_len>n) {
                struct node* del=haq_h;
                haq_h=haq_h->next;
                if(!haq_h) haq_t=NULL;
                free(del);
                haq_len--;
            }
        }


        if(cq_len>n) {
            struct node* del=cq_h;
            cq_h=cq_h->next;
            if(!cq_h) cq_t=NULL;
            free(del);
            cq_len--;
        }
    }

    if(haq_h)    
	{        
struct node *x=haq_h;        
printf("%d",x->v);        
x=x->next;        
while(x)        
{            
printf(" %d",x->v);            
x=x->next;        
}        
printf("\n");    
}    
else printf("-\n");
    if(cq_h)    
{        
struct node *x=cq_h;        
printf("%d",x->v);        
x=x->next;        
while(x)        
{            
printf(" %d",x->v);            
x=x->next;        
}    
}    
else printf("-");

}
