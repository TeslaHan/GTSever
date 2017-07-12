#ifndef GT_NET_MULITYTHREADS_H_
#define GT_NET_MULITYTHREADS_H_

#include <vector>
#include <thread>
namespace GT {
    namespace NET {

        class GT_ThreadPool
        {
        public:
            GT_ThreadPool();
            ~GT_ThreadPool();

        public:
            void Start(size_t poolsize, std::function<void()>);
            void Stop();

        private:
            void LongTimeWorker_(std::function<void()>);

        private:
            std::vector<std::thread> workpool_;
        };
    }
}


#endif // GT_NET_MULITYTHREADS_H_