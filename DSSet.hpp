#pragma once
/**The structure representing vertex - tree in the forest*/
struct DSSet
{
	int up, ///< up used to indicate a representative (top vertex of the set)
		rank; ///< rank vertex rank used when pinning to another set
};

