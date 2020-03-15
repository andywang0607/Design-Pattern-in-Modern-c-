#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <memory>
#include <vector>
#include <sstream>
using namespace std;

enum class OutputFormat
{
    markdown,
    html
};

// * hdajks
// * hdjask
// <ul>
// <li>dasjkdh</li>
// </ul>

struct ListStrategy
{
    virtual void start(ostringstream& oss){}
    virtual void add_list_item(ostringstream& oss, const string& item) = 0;
    virtual void end(ostringstream& oss){}
};
struct MarkdownListStrategy : ListStrategy{
    void add_list_item(ostringstream &oss, const string &item) override
    {
        oss << "* " << item << "\n";
    }
};

struct HtmlListStrategy : ListStrategy{
    void start(ostringstream& oss) override
    {
        oss << "<ul>\n";
    }
    void add_list_item(ostringstream &oss, const string &item) override
    {
        oss<< " <li>"<<item<<"</li>\n";
    }
    void end(ostringstream& oss) override
    {
        oss << "</ul>\n";
    }
};
struct TextProcessor
{
    void clear()
    {
        oss.str("");
        oss.clear();
    }
    void append_list(const vector<string>& items)
    {
        list_strategy->start(oss);
        for(auto &item : items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }
    void set_out_format(const OutputFormat& format)
    {
        switch(format){
            case OutputFormat::markdown:
                list_strategy = make_unique<MarkdownListStrategy>();
                break;
            case OutputFormat::html:
                list_strategy = make_unique<HtmlListStrategy>();
                break;
        }
    }
    string str() const { return oss.str(); }
private:
    ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};

int main(int ac, char* av[])
{
    vector<string> items{"foo", "bar", "baz"};

    TextProcessor tp;
    tp.set_out_format(OutputFormat::markdown);
    tp.append_list(items);
    cout << tp.str() << "\n";

    tp.clear();
    tp.set_out_format(OutputFormat::html);
    tp.append_list(items);
    cout << tp.str() << "\n";

    system("pause");
    return 0;
}