void compress(){
    map<int,int>mymap;
    int input[] = { -102, 1, 134565589,134565589, -102, 66666668,134565589, 66666668,
    -102, 1,-2};
    int assign=0;
    int cnt=0;
    int n=sizeof(input)/sizeof(int);
    int arr[n];
    for(int i=0;i<n;i++){
        int x=input[i];
        if(mymap.find(x)==mymap.end()){//if x not mapped yet.
            mymap[x]=assign;
            cout<<"Mapping "<<x<<" with "<<assign<<endl;
            assign++;
        }
        arr[cnt++]=mymap[x];//assigning new array's element
    }
    cout<<"The compreesed array is :";
    for(int i=0;i<cnt;i++)cout<<arr[i]<<" ";
}
//when string will give as the node of a graph .
//we can easily use array compression as a number.
//Let's have a look in the bellow code.
void compress(){
    map<int,int>mymap;
    
    int edge;
    cin>>edge;
    int assign=0;
    for(int i=0;i<edge;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(mymap.find(s1)==mymap.end()){
            cout<<s1<<" is mapped with "<<assign<<endl;
            mymap[s1]=assign++;
        }
        if(mymap.find(s2)==mymap.end()){
            cout<<s2<<" is mapped with "<<assign<<endl;
            mymap[s2]=assign++;
        }
        int u=mymap[s1];
        int v=mymap[s2];
        cout<<"edge :"<<u<<" "<<v<<endl;
    }
}
//If there any condition arise that the node will between -2^30 to 2^30 but the total node number will 10000.
//In order to handle this type of case we can use array compression.
