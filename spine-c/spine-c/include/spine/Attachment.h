/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software or
 * otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef SPINE_ATTACHMENT_H_
#define SPINE_ATTACHMENT_H_

#include <spine/dll.h>

#ifdef __cplusplus
extern "C" {
#endif

struct spAttachmentLoader;

typedef enum {
	SP_ATTACHMENT_REGION,
	SP_ATTACHMENT_BOUNDING_BOX,
	SP_ATTACHMENT_MESH,
	SP_ATTACHMENT_LINKED_MESH,
	SP_ATTACHMENT_PATH,
	SP_ATTACHMENT_POINT,
	SP_ATTACHMENT_CLIPPING
} spAttachmentType;

typedef struct spAttachment {
	const char *name;
	spAttachmentType type;
	const void *vtable;
	int refCount;
	struct spAttachmentLoader *attachmentLoader;
} spAttachment;

void spAttachment_dispose(spAttachment *self);

spAttachment *spAttachment_copy(spAttachment *self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_ATTACHMENT_H_ */
