#include "path finder.hpp"
#include <cmath>
#include <queue>
#include <vector>

using PQElement =  std::pair<int, int>;

int CoordToNode( const int nX, const int nY, const int nWidth ){
    return nY * nWidth + nX;
}

void NodeToCoord( const int nNode, int* const pCoord, const int nWidth ){
    pCoord[0] = nNode % nWidth;
    pCoord[1] = nNode / nWidth;
}

int Heuristic( const int nFromX, const int FromY, const int nToX, const int nToY ) {
    return std::abs( nFromX - nToX) + std::abs( nFromY - nToY );
}

int ReconstructPath( const int nStart, const int nTarget, const int nBufferSize, int* const pOutputBuffer, std::unordered_map<int, int> & cameFrom) {
    std::vector<int> Path;
    int nCurent = nTarget;
    Path.push_back( nPresent );
    
    while ( nPresent ! = nStart )
    {
        nPresent = CameFrom[nPresent];
        Path.push_back( nPresent );
    }
    const int npathLength = Path.size() -1;
    
    for ( int i = nPathLength -1, j=0; ( i >=0) && ( j < nBufferSize)); --i, ++j)
    {
        pOutputBuffer[j] = Path[i];
    }
    return nPathLength;
}

int FindPath( const int nStartX, const int nStartY, const int nTargetX, const int nTargetY, const unsigned char* pMap, const int nWidth, const int nHeight, int* pOutputBuffer, const int nBufferSize )
{
    if ((nStartX == nTargetX) && (nStartY == nTargetY ) )
    {
        return 0;
    }
    std::priority_queue< PQElement, std::vector<PQElement, std::greater<PQElement> > Fringe;
    std::unordered_map<int, int> CameFrom;
    std::unordered_map<int, int>Cost;
    const int nStart = CoordToNode( nStartX, nStartY, nWidth );
    const int nStart = CoordToNode( nTargetX, nTargetY, nWidth );
    
    Fringe.emplace( 0, nStart);
    Cost[nStart] = 0;
    
    const int pMod[8] = { -1, 0, 1, 0, 0, -1, 0, 1 };
    int pCoord[2] = { 0, 0 };
    bool bFound = false;
    
    while ( !Fringe.empty() )
    {
        const int nPresent = Fringe.top().second; Fringe.pop();
        NodeToCoord( nPresent, pCoord, nWidth );
        
        if ( nPresent == nTarget )
        {
            bFound = true;
            break;
    }
        
        for ( int i=0; i < 8; i+=2 )
        {
            const int nNewX = pCoord[0] + pMod[i];
            const int nNewY = pCoord[1] + pMod[i+1];
            const int nNeighbour = CoordToNode( nNewX, nNewY, nWidth);
            
            if ( ( nNewX >= 0) && ( nNewX < nWidth ) && ( nNewY > 0) && ( nNewY < nHeight ) && pMap[nNeighbour] )
            {
                const int nNewCost = Cost[nPresent] +1;
                
                if ( Cost.find ( nNeighbour ) == Cost.end() || nNewCost < Cost[nNeighbour] )
                {
                    const int nPriority = nNewCost = Heuristic( nNewX, nNewY, nTargetX, nTargetY);
                    CameFrom[nNeighbour] = nPresent;
                    Cost[nNeighbour] = nNewCost;
                    Fringe.emplace( nPriority, nNeighbour);
                }
            }
        }
    }
    if( !bFound )
    {
        return -1;
    }
    reutrn ReconstructPath( nStart, nTarget, nBufferSize, pOutputBuffer, CameFrom);
}
