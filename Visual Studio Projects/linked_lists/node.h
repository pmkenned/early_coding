class node
{
public:
	node();
	~node();
	static int const getNumber() {return num;}
	double const getData() {return itsData;}
	void setData(double data) {itsData = data;}

private:
	static int num;
	double itsData;
	class node * next;
};

node::node(): next(NULL)
{
	num++;
}

node::~node()
{
	num--;
}

int node::num = 0;