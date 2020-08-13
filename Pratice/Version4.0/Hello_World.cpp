#include <iostream>
#include "IPrintPlugin.h"

using namespace std;

int FUNC_ID = 2;

class CPrintPlugin : public ipp_t
{
public:
    CPrintPlugin()
    {
    }

    virtual ~CPrintPlugin()
    {
    }

    virtual void printSC()  // 打印 "Hello World!"
    {
        cout << "Hello World!" << endl;
    }

    virtual void help()     // 打印帮助信息
    {
        cout << "Function ID: " << FUNC_ID << " - This function is used to print HW" << endl;
    }

    virtual int getID()     // 返回插件ID
    {
        return FUNC_ID;
    }
};

extern "C" void createObj(ipp_t **ppPlugin) // 给主程序提供插件接口
{
    static CPrintPlugin plugin;
    *ppPlugin = &plugin;
}