//Copyright 2016 mustafa eral
//mustafaeral@gmail.com

//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
//to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
//and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef ActiveClsCLS_H_
#define ActiveClsCLS_H_

#include <stdio.h>
#include <pthread.h>

class ActiveCls {
    private:
        pthread_t thread;

    protected:

        void attach(void* (*tsk_fxn)(void* arg), int priority) {

            pthread_attr_t params;
            pthread_attr_init(&params);

            // let each task have 1MB of stack
            pthread_attr_setstacksize(&params, 0x100000);

            sched_param sch;
            pthread_attr_getschedparam(&params, &sch);
            sch.sched_priority = priority;

            pthread_create(&thread, &params, tsk_fxn, this);
            pthread_setschedparam(thread, SCHED_OTHER, &sch);

        }

    private:

        static void* run(void* obj) {

            return ((ActiveCls*) obj)->Run();
        }

    protected:

        virtual void* Run() {

            printf("Warning.. Run() function is not implemented for this class.\n");
            return 0;
        }

        ActiveCls(int pri = 1) {
            attach(&ActiveCls::run, pri);
        }
};

#endif /* ActiveClsCLS_H_ */
