class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans;
        for(int i=0;i*cost1<=total;i++){
            int remaining=total-i*cost1;

            int maxPencil=remaining/cost2;

            ans+=maxPencil+1;
        }
        return ans;
    }
};