  for(int i = 0; i < M; ) {
    int j;
    int num = 0;
    int tot = 0;

    set<pair<int, int> > st;
    for(j = i; j < M && E[j].first == E[i].first; j++) {
      int A = find(E[j].second.first);
      int B = find(E[j].second.second);
      if(B < A) swap(A, B);
      if(A != B) {
        st.insert(make_pair(A, B));
        tot++;
      }
    }
    assert(j - i <= 3);
    for(; i < j; i++) {
      num += merge(E[i].second.first, E[i].second.second);
    }
    
    mergs += num;
    cst += num * E[i - 1].first;
    if(tot == 3) {
      if(num == 1 || num == 2 && st.size() == 3) cnt = (cnt * 3) % MOD;
      if(num == 2 && st.size() == 2) cnt = (cnt * 2) % MOD;
    }
    if(tot == 2 && num == 1) cnt = (cnt * 2) % MOD;
  }