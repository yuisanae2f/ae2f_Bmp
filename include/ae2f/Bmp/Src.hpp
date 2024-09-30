#include "./Src.h"


#if defined(__cplusplus) && !defined(ae2f_Bmp_Src_hpp)
#define ae2f_Bmp_Src_hpp 

#include <ae2f/DataStructure/Allocator.hpp>

namespace ae2f {
	namespace Bmp {
		namespace BuildPrm {
			using Global = ae2f_Bmp_cSrc_Copy_Global;

			struct Indexed : private DataStructure::Allocator::cOwner::Linear_t {
				inline Indexed(uint8_t len, ae2f_errint_t* err = 0) noexcept 
					: DataStructure::Allocator::cOwner::Linear_t(
						len + sizeof(Global), 0, 0, err
					) {}

				constexpr		Global* GlobalBuff() noexcept {
					return this->data ? static_cast<Global*>(static_cast<void*>(this->data + sizeof(size_t))) : nullptr;
				}
				constexpr const Global* GlobalBuff() const noexcept {
					return this->data ? static_cast<const Global*>(static_cast<const void*>(this->data + sizeof(size_t))) : nullptr;
				}
				constexpr		uint8_t len() const noexcept {
					return this->data ? static_cast<const uint8_t*>(static_cast<const void*>(this->data))[0] : 0;
				}

				inline ~Indexed() noexcept {}
			};
		};

		struct cSrc : public ae2f_Bmp_cSrc {
			inline ae2f_errint_t Copy(
				const cSrc& src,
				const BuildPrm::Global& srcPrm
			) {
				switch (src.ElSize) {
				case ae2f_Bmp_Idxer_eBC_RGB:
				case ae2f_Bmp_Idxer_eBC_RGBA: break;
				default: return ae2f_errGlobal_WRONG_OPERATION;
				}
				return ae2f_Bmp_cSrc_Copy(this, &src, &srcPrm);
			}

			inline ae2f_errint_t Copy(
				const cSrc&& src,
				const BuildPrm::Global& srcPrm
			) {
				switch (src.ElSize) {
				case ae2f_Bmp_Idxer_eBC_RGB:
				case ae2f_Bmp_Idxer_eBC_RGBA: break;
				default: return ae2f_errGlobal_WRONG_OPERATION;
				}
				return ae2f_Bmp_cSrc_Copy(this, &src, &srcPrm);
			}

			inline ae2f_errint_t Copy(
				const cSrc& src,
				const BuildPrm::Global&& srcPrm
			) {
				switch (src.ElSize) {
				case ae2f_Bmp_Idxer_eBC_RGB:
				case ae2f_Bmp_Idxer_eBC_RGBA: break;
				default: return ae2f_errGlobal_WRONG_OPERATION;
				}
				return ae2f_Bmp_cSrc_Copy(this, &src, &srcPrm);
			}

			inline ae2f_errint_t Copy(
				const cSrc&& src,
				const BuildPrm::Global&& srcPrm
			) {
				switch (src.ElSize) {
				case ae2f_Bmp_Idxer_eBC_RGB:
				case ae2f_Bmp_Idxer_eBC_RGBA: break;
				default: return ae2f_errGlobal_WRONG_OPERATION;
				}
				return ae2f_Bmp_cSrc_Copy(this, &src, &srcPrm);
			}

			inline ae2f_errint_t Copy(
				const cSrc& src,
				const BuildPrm::Indexed& srcPrm
			) {
				if (srcPrm.len() < (1 << src.ElSize))
					return ae2f_errGlobal_WRONG_OPERATION;

				return ae2f_Bmp_cSrc_Copy(this, &src, srcPrm.GlobalBuff());
			}

			inline ae2f_errint_t Copy(
				const cSrc&& src,
				const BuildPrm::Indexed& srcPrm
			) {
				if (srcPrm.len() < (1 << src.ElSize))
					return ae2f_errGlobal_WRONG_OPERATION;

				return ae2f_Bmp_cSrc_Copy(this, &src, srcPrm.GlobalBuff());
			}
		};
	}
}

#endif // !defined(__cplusplus)
