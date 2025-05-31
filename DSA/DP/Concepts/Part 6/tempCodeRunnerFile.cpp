
        return dp3D[k][i][j] = max( kOrderLCS(v1,v2,k,i+1,j), kOrderLCS(v1,v2,k,i,j+1) );