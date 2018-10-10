#include<iostream>
#include<conio.h>
using namespace std;
struct staff
{
  int manager_kode;
  int worker_kode;
  bool is_admin;
  staff*next;
};
staff*begin2 = NULL;
struct stack
{
  int manager_kode;
  int worker_kode;
  bool is_admin;
  stack*next;
};
stack*beg_s = NULL;
void print_element(staff*element)
{
  cout << element->manager_kode << "---" << element->worker_kode << "---" << element->is_admin << "---" << element << endl;
}
void print_list(staff*begin)
{
  while (begin)
  {
    print_element(begin);
    begin = begin->next;
  }
}
void print_stack(stack*begin)
{
  while (begin)
  {
    cout << begin->manager_kode << "---" << begin->manager_kode << "---" << begin->is_admin << "---" << begin << endl;
    begin = begin->next;
  }
}
void delete_elem(staff**begin, staff*elem)
{
  if (*begin == elem)
  {
    staff*t = *begin;
    (*begin) = (*begin)->next;
    delete t;
  }
  else
  {
    staff*tmp = *begin;
    while (tmp->next != elem)
    {
      tmp = tmp->next;
    }
    staff*temp = tmp->next;
    tmp->next = temp->next;
    delete temp;
  }
}
void add_elem(staff**begin, int mk, int wk, bool isadm)
{
  if (*begin == NULL)
  {
    *begin = new staff;
    (*begin)->manager_kode = mk;
    (*begin)->worker_kode = wk;
    (*begin)->is_admin = isadm;
    (*begin)->next = NULL;
  }
  else
  {
    staff *t = new staff;
    t->manager_kode = mk;
    t->worker_kode = wk;
    t->is_admin = isadm;
    t->next = *begin;
    *begin = t;
  }
}
void add_elem_to_stack(stack**begin, int mk, int wk, bool isadm)
{
  if (*begin == NULL)
  {
    *begin = new stack;
    (*begin)->manager_kode = mk;
    (*begin)->worker_kode = wk;
    (*begin)->is_admin = isadm;
    (*begin)->next = NULL;
  }
  else
  {
    stack *t = new stack;
    t->manager_kode = mk;
    t->worker_kode = wk;
    t->is_admin = isadm;
    t->next = *begin;
    *begin = t;
  }
}
void pop_back(stack**beg)
{
  stack*t = *beg;
  *beg = (*beg)->next;
  delete t;
}
void add_from_stack(staff*begin)
{
  if (beg_s == NULL)
    return;
  if (begin->next->is_admin && (!begin->is_admin))
  {
    staff*t = new staff;
    t->manager_kode = beg_s->manager_kode;
    t->worker_kode = beg_s->worker_kode;
    t->is_admin = beg_s->is_admin;
    staff*t1 = begin->next;
    begin->next = t;
    t->next = t1;
    stack*t = beg_s;
    beg_s = beg_s->next;
    delete t;
  }
  else if (begin->worker_kode == begin->next->manager_kode)
  {
    staff*t = new staff;
    t->manager_kode = beg_s->manager_kode;
    t->worker_kode = beg_s->worker_kode;
    t->is_admin = beg_s->is_admin;
    staff*t1 = begin->next;
    begin->next = t;
    t->next = t1;
    stack*t = beg_s;
    beg_s = beg_s->next;
    delete t;
  }

}
void *delete_bad_list(staff *begin) {
  while (begin) {
    if (begin->next->is_admin && (!begin->is_admin)) { add_from_stack(begin); begin = begin->next;  }
    else if (begin->worker_kode == begin->next->manager_kode) { add_from_stack(begin); begin = begin->next;  }
    else {
      begin->is_admin = begin->next->is_admin;
      begin->worker_kode = begin->next->worker_kode;
      begin->manager_kode = begin->next->manager_kode;
      staff *temp;
      temp = begin->next;
      add_elem_to_stack(&beg_s, begin->next->manager_kode, begin->next->worker_kode, begin->next->is_admin);
      delete &begin->next;
      begin->next = temp->next;
    }
  }
}
int main()
{
  staff*begin = NULL;

  _getch();
  return 0;
}
