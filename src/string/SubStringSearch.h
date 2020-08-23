#pragma once
#include <string>
#include <vector>
namespace code047 {
	class SubStringSearch {
	public:
		SubStringSearch() {}
		virtual ~SubStringSearch() {}
	public:
		SubStringSearch(const SubStringSearch&) = delete;
		SubStringSearch& operator=(const SubStringSearch&) = delete;
	public:
		/// <summary>
		/// substring search
		/// </summary>
		/// <param name="txt">in which string that pat searching for</param>
		/// <param name="pat">pattern</param>
		/// <returns>first occurrence of pat</returns>
		virtual size_t searchFirstOccurrence(std::string& txt, std::string& pat) = 0;

		/// <summary>
		/// substring search
		/// </summary>
		/// <param name="txt">in which string that pat searching for</param>
		/// <param name="pat">pattern</param>
		/// <returns>all first occurrence of pat</returns>
		//virtual std::vector<size_t> searchAllOccurrence(std::string& txt, std::string& pat) = 0;
	};
}