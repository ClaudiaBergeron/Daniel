//
//  map2.h
//  MAP-AVL
//
//

#ifndef map2_h
#define map2_h

///////////////////////////////////////////////////////////////////////////
// lower_bound O(log n)

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::lower_bound(const Tclef& c)const {
	return iterator(nullptr);
}

///////////////////////////////////////////////////////////////////////////
//erase a partir d'une position

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::erase(iterator i) {
	assert(i != end());
	erase(i++->first);
	return i;
}

///////////////////////////////////////////////////////////////////////////
//insert a partir d'une position

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::insert(iterator j, const Tclef& c) {
	return insert(c).first;
}

///////////////////////////////////////////////////////////////////////////
//erase a partir d'une cle
template <typename Tclef, typename Tvaleur>
size_t map<Tclef, Tvaleur>::erase(const Tclef& c) {
	return 0;
}

///////////////////////////////////////////////////////////////////////////
// gestion de l'equilibre de l'arbre


//effectuer une rotation simple de la gauche vers la droite
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_gauche_droite(noeud*& p) {
}

//effectuer une rotation simple de la droite vers la gauche
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_droite_gauche(noeud*& p) {
}


#endif /* map2_h */
