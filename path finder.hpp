#ifndef PATH_HPP
#define PATH_HPP

#include <unordered_map>


int CoordToNode( const int nX, const int nY, const int nWidth );

void NodeToCoord( const int nNode, int* const pCoord, const int nWidth );

int Heuristic( const int nFromX, const int nFromY, const int nToX, const int nToY );

int ReconstructPath( const int nStart, const int nTarget, const int nBufferSize,
                    int* const pOutputBuffer, std::unordered_map<int, int>& CameFrom );


int FindPath( const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY,
             const unsigned char* pMap, const int nWidth, const int nHeight,
             int* pOutputBuffer, const int nBufferSize );

#end
