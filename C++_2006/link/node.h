class node
{
public:
  node();
  ~node();
  void print();
  class node * getNext() {return next;}
  void setData(double x) {data = x;}
  void setNext(class node * x) {next = x;}
private:
  double data;
  class node * next;
};

node::node(): next(NULL)
{}

node::~node()
{}

void node::print()
{
  cout << data << endl;
}