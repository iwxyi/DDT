#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // 窗口函数说明

// -------------------- 入口函数的代码 --------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hWnd;
    MSG msg;
    TCHAR szWindowClass[] = "窗口示例";   // 窗口类名
    TCHAR szTitle[]       = "我的窗口"; // 窗口标题名


    // ------------------- 初始化窗口类 -------------------

    wcex.cbSize        = sizeof(WNDCLASSEX);                                         // 窗口类的大小
    wcex.style         = 0;                                                          // 窗口类型为默认类型
    wcex.lpfnWndProc   = WndProc;                                                    // 窗口处理函数为 WndProc
    wcex.cbClsExtra    = 0;                                                          // 窗口类无扩展
    wcex.cbWndExtra    = 0;                                                          // 窗口实例无扩展
    wcex.hInstance     = hInstance;                                                  // 当前实例句柄
    wcex.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));      // 窗口的图标为默认图标
    wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);                                // 窗口采用箭头光标
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);                        // 窗口背景为白色
    wcex.lpszMenuName  = NULL;                                                       // 窗口中无菜单
    wcex.lpszClassName = szWindowClass;                                              // 窗口类名为“窗口实例”
    wcex.hIconSm       = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION)); // 窗口的小图标为默认图标


    // -------------------- 注册窗口类 --------------------

    if ( !RegisterClassEx(&wcex) ) // 如果注册失败则发出警告
    {
        MessageBox(NULL, _T("窗口类注册失败！"), _T("窗口注册"), NULL);
        return 1;
    }


    // --------------------- 创建窗口 ---------------------

    hWnd = CreateWindow(
               szWindowClass,                // 窗口类名
               szTitle,                      // 窗口实例的标题名
               WS_OVERLAPPEDWINDOW,          // 窗口的风格
               CW_USEDEFAULT, CW_USEDEFAULT, // 窗口左上角坐标为默认值
               CW_USEDEFAULT, CW_USEDEFAULT, // 窗口的高和宽为默认值
               NULL,                         // 无父窗口
               NULL,                         // 无主菜单
               hInstance,                    // 创建此窗口应用程序的当前句柄
               NULL                          // 如果创建窗口失败则发出警告
           );

    if ( !hWnd )
    {
        MessageBox(NULL, "创建窗口失败！", _T("创建窗口"), NULL);
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);         // 显示窗口
    UpdateWindow(hWnd);                 // 绘制用户区

    while(GetMessage(&msg, NULL, 0, 0)) // 消息循环
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;            // 程序终止时将信息返回系统
}


// ----------------------- 窗口函数 -----------------------

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_DESTROY :
        PostQuitMessage(0); // 发出 WM_QUIT 消息，没有这句话则只是关闭窗口但进程不会停止
        break;
    default :
        return DefWindowProc(hWnd, message, wParam, lParam); // 默认时采用系统消息默认处理函数
        break;
    }

    return 0;
}
