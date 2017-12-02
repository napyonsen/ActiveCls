# ActiveCls
classes inherited from this class, can run. Uses pthreads internally. 


example:
'''
class AnActiveCls : public ActiveCls()
{
    public:
      void* Run()   {
                 cout<<"Heyo, I am running..";
                 return NULL;
                }
}
'''
