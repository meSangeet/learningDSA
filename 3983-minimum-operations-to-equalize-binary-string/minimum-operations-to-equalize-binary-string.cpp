class Solution {
public:
  int minOperations(string s, int k) {
    // a state is defined by number of 0s we currently have
    // treat every state as a node we want to visit;
    // track nodes in sets (separately for even and odd numbers, because of which transitions are possible)
    // after visiting a node - remove it from the corresponding set:
    // visiting the same node twice would correspond to some sequence
    // of operations that go through the same number of zeros twice - we don't want that
    const int n = std::ssize(s);
    std::set<int> oddNodes, evenNodes;
    for (int i = 0; i <= n; ++i) {  
      if (i % 2 == 0)
        evenNodes.insert(i);
      else
        oddNodes.insert(i);
    }

    int cnt0 = ranges::count(s, '0');
    std::queue<int> q;
    q.push(cnt0);
    if (cnt0 % 2 == 0) 
      evenNodes.erase(cnt0);
    else
      oddNodes.erase(cnt0);

    int dist = 0;
    while (!q.empty()) {
      const int layerSize = std::ssize(q);
      for (int i = 0; i < layerSize; ++i) {
        cnt0 = q.front();
        q.pop();
        if (cnt0 == 0)
          return dist;

        int cnt1 = n - cnt0;

        // how many 0s we can flip?
        int canFlipMax = std::min(cnt0, k);
        // e.g. there's only a single '1', we must flip at least k - 1 0-s
        int canFlipMin = std::max(0, k - cnt1);

        // suppose we flip p zeros...
        // we'll get into a state 'cnt0 - p + (k - p)' = 'cnt0 + k - 2p'
        // note that only states with parity same a of 'cnt0 + k' are reachable
        auto *reachableStates = (cnt0 + k) % 2 == 0 ? &evenNodes : &oddNodes;

        // check all reachable states
        int nextMin = cnt0 - canFlipMax + (k - canFlipMax);
        int nextMax = cnt0 - canFlipMin + (k - canFlipMin);
        while (true) {
          auto it = reachableStates->lower_bound(nextMin);
          if (it == end(*reachableStates) || *it > nextMax)
            break;
          q.push(*it);
          reachableStates->erase(it);
        }
      }

      ++dist;
    }

    return -1;
  }
};