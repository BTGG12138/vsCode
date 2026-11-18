#include <iostream>
#include <string>
#include <fstream>

// 1. 策略接口
class PrintStrategy {
public:
    virtual ~PrintStrategy() = default; 
    // 关键修复：在函数末尾添加 const
    virtual void print(const std::string& data) const = 0; 
};

// 2. 具体策略A
class ConsolePrintStrategy : public PrintStrategy {
public:
    // 派生类重写时也必须保持 const 一致
    void print(const std::string& data) const override {
        std::cout << "Console: " << data << std::endl;
    }
};

// 3. 具体策略B
class FilePrintStrategy : public PrintStrategy {
public:
    // 派生类重写时也必须保持 const 一致
    void print(const std::string& data) const override {
        std::ofstream outFile("report.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << "File: " << data << std::endl;
            outFile.close();
            std::cout << "[系统提示] 报告已成功写入 report.txt 文件" << std::endl;
        }
    }
};

// 4. 上下文类
class ReportGenerator {
private:
    const PrintStrategy& strategy; // 这里是 const 引用，要求调用的函数也必须是 const
public:
    ReportGenerator(const PrintStrategy& strat) : strategy(strat) {}
    
    void generateReport() {
        std::string reportData = "2023年度财务报告 - 净利润：100万";
        std::cout << "正在生成报告数据..." << std::endl;
        // 现在可以正常调用，因为 print 是 const 成员函数
        strategy.print(reportData); 
    }
};

int main() {
    ConsolePrintStrategy consoleStrategy;
    FilePrintStrategy fileStrategy;

    ReportGenerator report1(consoleStrategy);
    report1.generateReport();

    ReportGenerator report2(fileStrategy);
    report2.generateReport();

    return 0;
}