#include "student_code.h"
#include "mutablePriorityQueue.h"

using namespace std;

namespace CGL
{
    
  Vector2D lerp(float t, Vector2D p0, Vector2D p1) {
    Vector2D midP;
    midP.x = (1 - t) * p0.x + t * p1.x;
    midP.y = (1 - t) * p0.y + t * p1.y;
      
    return midP;
  }
  /**
   * Evaluates one step of the de Casteljau's algorithm using the given points and
   * the scalar parameter t (class member).
   *
   * @param points A vector of points in 2D
   * @return A vector containing intermediate points or the final interpolated vector
   */
  std::vector<Vector2D> BezierCurve::evaluateStep(std::vector<Vector2D> const &points)
  { 
    // TODO Part 1.
      vector<Vector2D> intermediates;
      for (int i = 0; i < points.size() - 1; i++) intermediates.push_back(lerp(t, points[i], points[i + 1]));
      
      return intermediates;
  }

  Vector3D lerp3D(double t, Vector3D p0, Vector3D p1) {
      Vector3D midP;
      midP.x = (1 - t) * p0.x + t * p1.x;
      midP.y = (1 - t) * p0.y + t * p1.y;
      midP.z = (1 - t) * p0.z + t * p1.z;
        
      return midP;
    }

  /**
   * Evaluates one step of the de Casteljau's algorithm using the given points and
   * the scalar parameter t (function parameter).
   *
   * @param points    A vector of points in 3D
   * @param t         Scalar interpolation parameter
   * @return A vector containing intermediate points or the final interpolated vector
   */
  std::vector<Vector3D> BezierPatch::evaluateStep(std::vector<Vector3D> const &points, double t) const
  {
    // TODO Part 2.
    vector<Vector3D> intermediates;
    for (int i = 0; i < points.size() - 1; i++) intermediates.push_back(lerp3D(t, points[i], points[i + 1]));
      
    return intermediates;
  }

  /**
   * Fully evaluates de Casteljau's algorithm for a vector of points at scalar parameter t
   *
   * @param points    A vector of points in 3D
   * @param t         Scalar interpolation parameter
   * @return Final interpolated vector
   */
  Vector3D BezierPatch::evaluate1D(std::vector<Vector3D> const &points, double t) const
  {
      // TODO Part 2.
      if (points.size() == 1) {
          return points[0];
      }
      return evaluate1D(evaluateStep(points, t), t);
  }

  /**
   * Evaluates the Bezier patch at parameter (u, v)
   *
   * @param u         Scalar interpolation parameter
   * @param v         Scalar interpolation parameter (along the other axis)
   * @return Final interpolated vector
   */
  Vector3D BezierPatch::evaluate(double u, double v) const 
  {
      
      vector<Vector3D> points;
      for (int i = 0; i < controlPoints.size(); i++) {
          points.push_back(evaluate1D(controlPoints[i], u));
      }
    return evaluate1D(points, v);
  }
/*
  Vector3D crossProduct(Vector3D p0, Vector3D p1) {
        Vector3D point;
        point.x = p0.y * p1.z - p1.y * p0.z;
        point.y = -1 * (p0.x * p1.z - p1.x * p0.z);
        point.z = p0.x * p1.y - p1.x * p0.y;
      return point;
    }
*/
  Vector3D Vertex::normal( void ) const
  {
    // TODO Part 3.
    // Returns an approximate unit normal at this vertex, computed by
    // taking the area-weighted average of the normals of neighboring
    // triangles, then normalizing.
      
     // double area = 0.0;
      HalfedgeCIter h = halfedge();
      Vector3D pos = Vector3D(0,0,0);
      do
      {
        VertexCIter currVertex = h->vertex();
        HalfedgeCIter h_twin = h->twin();
        VertexCIter neighborVertex = h_twin->vertex();
          
        Vector3D v0 = currVertex->position;
        Vector3D v1 = neighborVertex->position;
        Vector3D v2 = h_twin->next()->next()->vertex()->position;
          
        Vector3D v0v1 = Vector3D(v1.x - v0.x, v1.y - v0.y, v1.z - v0.z);
        Vector3D v0v2 = Vector3D(v2.x - v0.x, v2.y - v0.y, v2.z - v0.z);
          
        Vector3D vector = cross(v0v2, v0v1);
          
        pos.x += vector.x;
        pos.y += vector.y;
        pos.z += vector.z;
        
        h = h_twin->next();
      } while (h != halfedge());
    
    return pos.unit();
  }

  EdgeIter HalfedgeMesh::flipEdge( EdgeIter e0 )
  {
    // TODO Part 4.
    // This method should flip the given edge and return an iterator to the flipped edge.
      
      //I have the corresponding address at this halfedge
      HalfedgeIter h0 = e0->halfedge();

      if (!h0->isBoundary()) {
          //HalfEdges
          HalfedgeIter h1 = h0->next();
          HalfedgeIter h2 = h1->next();
          
          HalfedgeIter h3 = h0->twin();
          
          HalfedgeIter h4 = h3->next();
          HalfedgeIter h5 = h4->next();
          
          HalfedgeIter h6 = h1->twin();
          HalfedgeIter h7 = h2->twin();
          HalfedgeIter h8 = h4->twin();
          HalfedgeIter h9 = h5->twin();
          
          
          //Vertices
          VertexIter v0 = h0->vertex();
          VertexIter v1 = h1->vertex();
          VertexIter v2 = h2->vertex();
          VertexIter v3 = h5->vertex();
          
          //Faces
          FaceIter f0 = h0->face(); //h face
          FaceIter f1 = h3->face(); //twin face
          
          //Edges
          EdgeIter e1 = h1->edge();
          EdgeIter e2 = h2->edge();
          EdgeIter e3 = h4->edge();
          EdgeIter e4 = h5->edge();
          
          h0->setNeighbors(h1, h3, v3, e0, f0);
          h1->setNeighbors(h2, h7, v2, e2, f0);
          h2->setNeighbors(h0, h8, v0, e3, f0);
          h3->setNeighbors(h4, h0, v2, e0, f1);
          h4->setNeighbors(h5, h9, v3, e4, f1);
          h5->setNeighbors(h3, h6, v1, e1, f1);
          h6->setNeighbors(h6->next(), h5, v2, e1, h6->face());
          h7->setNeighbors(h7->next(), h1, v0, e2, h7->face());
          h8->setNeighbors(h8->next(), h2, v3, e3, h8->face());
          h9->setNeighbors(h9->next(), h4, v1, e4, h9->face());
          
          v0->halfedge() = h2;
          v1->halfedge() = h5;
          v2->halfedge() = h3;
          v3->halfedge() = h0;
          
          e0->halfedge() = h0;
          e1->halfedge() = h6;
          e2->halfedge() = h7;
          e3->halfedge() = h8;
          e4->halfedge() = h9;
          
          f0->halfedge() = h0;
          f1->halfedge() = h3;
      }
      e0 = h0->edge();
    return e0;
  }

  VertexIter HalfedgeMesh::splitEdge( EdgeIter e0 )
  {
    // TODO Part 5.
    // This method should split the given edge and return an iterator to the newly inserted vertex.
    // The halfedge of this vertex should point along the edge that was split, rather than the new edges.
      HalfedgeIter h0 = e0->halfedge();
      
      if (!e0->isBoundary()) {
          
         
        //Halfedges
          HalfedgeIter h1 = h0->next();
          HalfedgeIter h2 = h1->next();
          
          HalfedgeIter h3 = h0->twin();
          HalfedgeIter h4 = h3->next();
          HalfedgeIter h5 = h4->next();
              
          HalfedgeIter h6 = h1->twin();
          HalfedgeIter h7 = h2->twin();
          HalfedgeIter h8 = h4->twin();
          HalfedgeIter h9 = h5->twin();
            
          //Vertices
          VertexIter v0 = h0->vertex();
          VertexIter v1 = h3->vertex();
          VertexIter v2 = h2->vertex();
          VertexIter v3 = h5->vertex();
              
          //Faces
          FaceIter f0 = h0->face(); //h face
          FaceIter f1 = h3->face(); //twin face
              
          //Edges
          EdgeIter e1 = h1->edge();
          EdgeIter e2 = h2->edge();
          EdgeIter e3 = h4->edge();
          EdgeIter e4 = h5->edge();
              
          //New added components
          HalfedgeIter h00 = newHalfedge();
          HalfedgeIter h01 = newHalfedge();
          HalfedgeIter h02 = newHalfedge();
          HalfedgeIter h03 = newHalfedge();
          HalfedgeIter h04 = newHalfedge();
          HalfedgeIter h05 = newHalfedge();
          
          VertexIter midVertex = newVertex();
          Vector3D vertex1 = v0->position;
          Vector3D vertex2 = v1->position;
          midVertex->position = (vertex1 + vertex2) / 2;
        
          midVertex->halfedge() = h00;
          
          EdgeIter e01 = newEdge();
          EdgeIter e02 = newEdge();
          EdgeIter e03 = newEdge();
          
          FaceIter f01 = newFace();
          FaceIter f02 = newFace();
          
          h0->setNeighbors(h1, h3, midVertex, e0, f0);
          
          h1->setNeighbors(h02, h6, v1, e1, f0);
          
          h2->setNeighbors(h00, h7, v2, e2, f01);
          
          h3->setNeighbors(h05, h0, v1, e0, f1);
          
          h4->setNeighbors(h04, h8, v0, e3, f02);
          h5->setNeighbors(h3, h9, v3, e4, f1);
          
          h00->setNeighbors(h01, h03, v0, e02, f01);
          
          h01->setNeighbors(h2, h02, midVertex, e01, f01);
          h02->setNeighbors(h0, h01, v2, e01, f0);
          
          h03->setNeighbors(h4, h00, midVertex, e02, f02);
          
          h04->setNeighbors(h03, h05, v3, e03, f02);
          h05->setNeighbors(h5, h04, midVertex, e03, f1);
          
          e01->halfedge() = h02;
          e02->halfedge() = h00;
          e03->halfedge() = h04;
          
          midVertex->isNew = true;
          e0->isNew = false;
          e01->isNew = true;
          e02->isNew = false;
          e03->isNew = true;
          
          f0->halfedge() = h0;
          f1->halfedge() = h3;
          f01->halfedge() = h2;
          f02->halfedge() = h4;
          
          return midVertex;
      }
    return e0->halfedge()->vertex();
  }

void checkEdgeFlip(EdgeIter edge, EdgeIter end, HalfedgeMesh& mesh) {
    while (edge != end) {
        EdgeIter edgeNext = edge;
        edgeNext++;
        
        if (edge->isNew) {
            HalfedgeIter h = edge->halfedge();
            VertexIter v0 = h->vertex();
            VertexIter v1 = h->twin()->vertex();
            if ((v0->isNew && !v1->isNew) || (!v0->isNew && v1->isNew)) {
                mesh.flipEdge(edge);
            }
        }
        edge = edgeNext;
    }
        
}
void updateVertices(VertexIter vertex, VertexIter end) {
    while (vertex != end) {
        vertex->position = vertex->newPosition;
        vertex++;
    }
}


  void MeshResampler::upsample( HalfedgeMesh& mesh )
  {
    // TODO Part 6.
    // This routine should increase the number of triangles in the mesh using Loop subdivision.
      EdgeIter edge = mesh.edgesBegin();
      int count = 0;
      while (edge != mesh.edgesEnd()) {
          count++;
          EdgeIter edgeNext = edge;
          edgeNext++;
          
          HalfedgeIter halfEdge = edge->halfedge();
          
          VertexIter A = halfEdge->vertex();
          VertexIter B = halfEdge->twin()->vertex();
          VertexIter C = halfEdge->next()->next()->vertex();
          VertexIter D = halfEdge->twin()->next()->next()->vertex();
          
          edge->newPosition = 3.0/8.0 * (A->position + B->position) + 1.0/8.0 * (C->position + D->position);
          
          //edgeNext->isNew = false;
          edge = edgeNext;
      }
      
      VertexIter vertex = mesh.verticesBegin();
      
      while (vertex != mesh.verticesEnd()) {
          Vector3D ogNeighbor = Vector3D(0,0,0);
          vertex->isNew = false;
          VertexIter vertexNext = vertex;
          vertexNext++;
          double n = 0.0;
          double u;
          
          HalfedgeIter halfEdge = vertex->halfedge();
          do {
              ogNeighbor += halfEdge->twin()->vertex()->position;
              halfEdge = halfEdge->twin()->next();
              n++;
          }while (halfEdge != vertex->halfedge());
          
          if (n == 3.0) {
              u = 3.0 / 16.0;
          } else {
              u = 3.0 / (8.0 * n);
              
          }
          Vector3D original = vertex->position;
          vertex->newPosition = (1.0 - n * u) * original + u * ogNeighbor;
          vertex = vertexNext;
      }
      
      edge = mesh.edgesBegin();
      for (int i = 0; i < count; i++) {
          EdgeIter edgeNext = edge;
          edgeNext++;
          
          VertexIter vertex = mesh.splitEdge(edge);
          vertex->newPosition = edge->newPosition;
          edge = edgeNext;
      }

      checkEdgeFlip(mesh.edgesBegin(), mesh.edgesEnd(), mesh);
      
      updateVertices(mesh.verticesBegin(), mesh.verticesEnd());
      
      
      
  }
}
